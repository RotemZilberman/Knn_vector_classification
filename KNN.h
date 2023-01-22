//Rotem Zilberman 213231418
//Ohad Langer

#ifndef ADVANCED_PROGRAMIN_PART2_KNN_H
#define ADVANCED_PROGRAMIN_PART2_KNN_H

#include <vector>
#include "TestFinding.h"
#include "MathVector.h"
#include "ClassifiedCollection.h"
/**
 * this is the KNN class
 */
class KNN{
private:
    ClassifiedCollection classified;
    /**
     * find the median in the select
     * @param arr is the array
     * @param n is the size
     * @return the median element
     */
    double findMedian(double arr[], int n);
    /**
     * doing simple swap
     * @param a is a element
     * @param b is a element
     */
    void swap(double &a, double &b);
    /**
     * doing simple swap between TestFinding
     * @param a is a element
     * @param b is a element
     */
    void swapTest(TestFinding&a, TestFinding &b);
    /**
     * doing a partitionArray for the value x
     * @param arr is the array
     * @param s is the start point
     * @param n is the end point
     * @param x is the val
     * @return the position
     */
    int partitionArray(double arr[], int s, int n, double x);
    /**
     * finding the kth element
     * @param arr is the array
     * @param s is the start point
     * @param e is the end point
     * @param k is the required position
     * @return the kth element
     */
    double kthSmallest(double arr[], int s, int e, int k);
    /**
     * doing partitionArray for Finding respectively with x
     * @param classifiedFindings
     * @param x is the val
     */
    void partitionFinding(std::vector<TestFinding> &classifiedFindings, double x);
    /**
     * return vector TestFinding with the k closest elements
     * @param unClassified is the unclassified vector
     * @param math is the distance object
     * @param k is the wanted k
     * @return vector TestFinding with the k closest elements
     */
    std::vector<TestFinding> kClosest(std::vector<double> &unClassified, MathVector& math,  int k);
    /**
     * sort the arr
     * @param start is the start point of the array
     * @param end is the end point of the array
     */
    void sort(double *start, double *end);
public:
    /**
     * is the KNN constructor
     * @param classified is the classified collection
     */
    KNN(ClassifiedCollection &classified);
    /**
     * return the classification for the vector
     * @param unClassified is the vector
     * @param math is the distance object
     * @param k is the k closest element
     * @return the classification
     */
    std::string classification(std::vector<double> &unClassified, MathVector math, int k);
};
#endif //ADVANCED_PROGRAMIN_PART2_KNN_H
