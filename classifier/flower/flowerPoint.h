#ifndef ASS_ONE_FLOWER_POINT_H
#define ASS_ONE_FLOWER_POINT_H

/**
 * @brief The FlowerPoint class
 *
 * This class represents a FlowerPoint with 4 parameters.
 * the parameters are:
 * - width (double)
 * - sepal length (double)
 * - sepal width (double)
 * - petal length (double)
 */
class FlowerPoint {
    private:
        double width;
        double sepalLength;
        double sepalWidth;
        double petalLength;

    public:
        /**
         * Constructor.
         * @param width width of the flower
         * @param sepalLength  sepal length of the flower
         * @param sepalWidth sepal width of the flower
         * @param petalLength petal length of the flower
         */
        FlowerPoint(double width, double sepalLength, double sepalWidth, double petalLength);

        /**
         * @return the width of the flower (double)
         */
        double getWidth() const;

        /**
         * @return the sepal length of the flower (double)
         */
        double getSepalLength() const;

        /**
         * @return the sepal width of the flower (double)
         */
        double getSepalWidth() const;

        /**
         * @return the petal length of the flower (double)
         */
        double getPetalLength() const;
};

#endif //ASS_ONE_FLOWER_POINT_H