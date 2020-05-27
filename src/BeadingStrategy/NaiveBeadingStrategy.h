//Copyright (c) 2019 Ultimaker B.V.


#ifndef NAIVE_BEADING_STRATEGY_H
#define NAIVE_BEADING_STRATEGY_H

#include "BeadingStrategy.h"

namespace arachne
{
    using namespace cura;

/*!
 * Beading strategy which evenly subdivides the thickness and tries to stay close to the optimal width.
 */
class NaiveBeadingStrategy : public BeadingStrategy
{
public:
    NaiveBeadingStrategy(const coord_t bead_width)
    : BeadingStrategy(bead_width, /*default_transition_length=*/ 10, 0)
    {
    }
    virtual ~NaiveBeadingStrategy() override
    {}
    Beading compute(coord_t thickness, coord_t bead_count) const override;
    coord_t getOptimalThickness(coord_t bead_count) const override;
    coord_t getTransitionThickness(coord_t lower_bead_count) const override;
    coord_t getOptimalBeadCount(coord_t thickness) const override;
    virtual std::string toString() const override { return "NaiveBeadingStrategy";}
};




} // namespace arachne
#endif // NAIVE_BEADING_STRATEGY_H