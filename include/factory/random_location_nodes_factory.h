

#ifndef WSN_RANDOM_NODES_FACTORY_H
#define WSN_RANDOM_NODES_FACTORY_H

#include <model/point.h>
#include <model/nodes.h>
#include <random>
#include "nodes_factory.h"
#include <algorithm>

namespace wsn {

    namespace factory {

        struct RandomNodeArea {

            RandomNodeArea(const wsn::model::Point &min, const wsn::model::Point &max) {
                if(min.x > max.x || min.y > max.y || min.z > max.z)
                    throw std::invalid_argument("Min border values must be less then max");

                this->min = min;
                this->max = max;
            }

        public:
            const wsn::model::Point& getMin() const {
                return  min;
            }

            const wsn::model::Point& getMax() const {
                return max;
            }

        private:

            wsn::model::Point min;
            wsn::model::Point max;

        };

        template <typename NodeType>
        class RandomNodesFactory : public NodesFactory<NodeType> {

        public:
            explicit RandomNodesFactory(const wsn::factory::RandomNodeArea &area) : area(area), seed(time(NULL)) {
            }

            RandomNodesFactory(const wsn::factory::RandomNodeArea &area, long seed) : area(area), seed(seed) {

            }

            std::shared_ptr<wsn::model::Nodes<NodeType>> buildNodes(unsigned long nodeCounts) override {

                std::vector<float> xs(nodeCounts);
                std::vector<float> ys(nodeCounts);
                std::vector<float> zs(nodeCounts);

                float xstep = calculatePossibleStepDistribution(area.getMax().x - area.getMin().x, nodeCounts);
                float ystep = calculatePossibleStepDistribution(area.getMax().y - area.getMin().y, nodeCounts);
                float zstep = calculatePossibleStepDistribution(area.getMax().z - area.getMin().z, nodeCounts);

                float x = area.getMin().x;
                float y = area.getMin().y;
                float z = area.getMin().z;
                for (unsigned int i = 0; i < nodeCounts; ++i, x+= xstep, y+=ystep, z+=zstep) {
                    xs[i] = x;
                    ys[i] = y;
                    zs[i] = z;
                }

                //TODO threads optimizations
                std::random_shuffle(xs.begin(), xs.end());
                std::random_shuffle(ys.begin(), ys.end());
                std::random_shuffle(zs.begin(), zs.end());

                auto nodes = std::make_shared<wsn::model::Nodes<NodeType>>();
                for (int i = 0; i < nodeCounts; ++i) {

                    nodes->addNode(std::make_unique<NodeType>(i, wsn::model::Point(xs[i], ys[i], zs[i]), 0.5, 1000));
                }


                /*
                std::default_random_engine generator(seed);
                std::uniform_real_distribution<float> x_r(area.min.x, area.min.y);
                std::uniform_real_distribution<float> y_r(area.min.y, area.max.y);
                std::uniform_real_distribution<float> z_r(area.min.z, area.max.z);

                for (int i = 0; i < nodeCounts; ++i) {

                    nodes->addNode(std::make_unique<NodeType>(i, wsn::model::Point(x_r(generator), y_r(generator), z_r(generator)), 0.5, 1000));
                }*/

                return nodes;
            }

        private:
            const RandomNodeArea area;
            const long seed;

            float calculatePossibleStepDistribution(float areaLength, unsigned long nodeCounts) {
                return areaLength - nodeCounts >= 0 ? 1 : areaLength / nodeCounts;
            }

        };

    }

}
#endif //WSN_RANDOM_NODES_FACTORY_H
