//Rotem Zilberman 213231418
//Ohad Langer

#ifndef UNTITLED12_SETTINGS_H
#define UNTITLED12_SETTINGS_H
#include "ClassifiedCollection.h"
#include "UnclassifiedCollection.h"
#include "DefaultIO.h"

class Settings {
    private:
        DefaultIO &io;
        ClassifiedCollection classified;
        UnclassifiedCollection unclassified;
        ClassifiedCollection result;
        int k;
        MathVector math;
        bool wasUploaded;
        bool resume;
        bool wasClassed;

public:
    Settings(DefaultIO &io);
    DefaultIO &getDefaultIO();
    std::string getKNNParam();
    /**
     * set K
     * @param newK is the new K
     */
    void setK(int newK);
    /**
     * set Distance
     * @param dis is the new dis
     */
    void setDistance(std::string dis);
    /**
     * push back unclassified vector
     * @param vec is the vector
     */
    void push_back_unclass(std::vector<double> vec);
    /**
     * push back classified vector
     * @param vec is the vector
     */
    void push_back_class(ClassifiedVector vec);
    /**
     * push back result vector
     * @param vec is the vector
     */
    void push_back_result(ClassifiedVector vec);
    /**
     * restart the setting
     */
    void init_collections();
    /**
     * update state of the loaded
     * @param loaded is the state
     */
    void updateLoaded(bool loaded);
    /**
    * update state of the resume
    * @param res is the state
    */
    void updateResume(bool res);
    /**
    * update state of the classed
    * @param classed is the state
    */
    void updateClassified(bool classed);
    /**
     * get loaded
     * @return the loaded
     */
    bool getLoaded();
    /**
    * get resume
    * @return the resume
    */
    bool getResume();
    /**
    * get Classified state
    * @return the Classified state
    */
    bool getClassified();
    /**
     * get Unclassified Collection
     * @return the Unclassified Collection
     */
    UnclassifiedCollection get_unclass();
    /**
    * get ClassifiedCollection Collection
    * @return the ClassifiedCollection Collection
    */
    ClassifiedCollection get_classified();
    /**
    * get result Collection
    * @return the result Collection
    */
    ClassifiedCollection get_result();
    /**
     * return the MathVector
     * @return is the mathVector
     */
    MathVector getMath();
    /**
     * return the k
     * @return the k
     */
    int getK();
};


#endif //UNTITLED12_SETTINGS_H
