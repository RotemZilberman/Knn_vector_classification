//Rotem Zilberman 213231418
//Ohad Langer
#include <map>
#include "KNN.h"
KNN::KNN(ClassifiedCollection &inputClassified) : classified(inputClassified) {}

std::vector<TestFinding> KNN::kClosest(std::vector<double> &unClassified, MathVector &math, int k) {
    std::vector<TestFinding> classifiedFindings = classified.result(unClassified, math);
    double arr[classifiedFindings.size()];
    for(int i =0; i<classifiedFindings.size(); i++){
        arr[i] = classifiedFindings[i].GetDistance();
    }
    double kthElement = kthSmallest(arr,0,(int)classifiedFindings.size()-1,k);
    if(kthElement == -1) {
        throw std::invalid_argument("invalid input");
    }
    partitionFinding(classifiedFindings, kthElement);
    return classifiedFindings;
}

double KNN::kthSmallest(double arr[], int s, int e, int k) {
    if (k > 0 && k <= e - s + 1) {
        int n = e - s + 1;
        int i;
        double median[(n+4)/5];
        for (i=0; i<n/5; i++)
            median[i] = findMedian(arr + s + i * 5, 5);
        if (i*5 < n) {
            median[i] = findMedian(arr + s + i * 5, n % 5);
            i++;
        }
        double medOfMed = (i == 1)? median[i-1] : kthSmallest(median, 0, i - 1, i / 2);
        int p = partitionArray(arr, s, e, medOfMed);
        if (p - s == k - 1)
            return arr[p];
        if (p - s > k - 1)
            return kthSmallest(arr, s, p - 1, k);
        return kthSmallest(arr, p + 1, e, k - p + s - 1);
    }
    return -1;
}

void KNN::swap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

void KNN::swapTest(TestFinding &a, TestFinding &b) {
    TestFinding temp = a;
    a = b;
    b = temp;
}

double KNN::findMedian(double *arr, int n) {
    sort(arr, arr+n);
    return arr[n/2];
}

void KNN::sort(double *start, double *end) {
    int i, j;
    int n = (end-start)/sizeof(double);
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (start[j] > start[j + 1])
                swap(start[j], start[j + 1]);
}

int KNN::partitionArray(double *arr, int s, int n, double x) {
    int i;
    for (i=s; i < n; i++)
        if (arr[i] == x)
            break;
    swap(arr[i], arr[n]);
    i = s;
    for (int j = s; j <= n - 1; j++) {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[n]);
    return i;
}

void KNN::partitionFinding(std::vector<TestFinding> &classifiedFindings, double x) {
    int i=0;
    for (TestFinding test : classifiedFindings) {
        if (test.GetDistance() == x)
            break;
        i++;
    }
    swapTest(classifiedFindings[i], classifiedFindings[classifiedFindings.size()-1]);
    i = 0;
    for (int j = 0; j <= classifiedFindings.size()-2; j++) {
        if (classifiedFindings[j].GetDistance() <= x) {
            swapTest(classifiedFindings[i], classifiedFindings[j]);
            i++;
        }
    }
    swapTest(classifiedFindings[i], classifiedFindings[classifiedFindings.size()-1]);
}

std::string KNN::classification(std::vector<double> &unClassified, MathVector math, int k) {
    std::vector<TestFinding> result = kClosest(unClassified,math, k);
    std::map<std::string, int> analyst;
    for (int i =0; i<k;i++) {
        if(analyst.find(result[i].GetClassification())!=analyst.end()){
            analyst[result[i].GetClassification()]++;
        }
        else{
            analyst[result[i].GetClassification()] = 1;
        }
    }
    std::string maxVal;
    int maxCount=0;
    for(auto &val : analyst){
        if(val.second>maxCount){
            maxCount = val.second;
            maxVal = val.first;
        }
    }
    return maxVal;
}

