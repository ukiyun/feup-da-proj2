#include "../include/ToyGraph.h"

ToyGraph::ToyGraph(int origin, int destination, double distance, string label_origin, string label_destination) {
    this->origin_ = origin;
    this->destination_ = destination;
    this->distance_ = distance;
    this->label_origin_ = label_origin;
    this->label_destination_ = label_destination;
}

int ToyGraph::getOrigin() const {
    return this->origin_;
}

int ToyGraph::getDestination() const {
    return this->destination_;
}

double ToyGraph::getDistance() const {
    return this->distance_;
}

string ToyGraph::getOriginLabel() const {
    return this->label_origin_;
}

string ToyGraph::getDestinationLabel() const {
    return this->label_destination_;
}
