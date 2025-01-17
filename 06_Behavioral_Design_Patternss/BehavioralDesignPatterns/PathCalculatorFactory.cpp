//#include "PathCalculatorFactory.h"
//
//std::unique_ptr<PathCalculator>
//PathCalculatorFactory::GetPathCalculatorForMode(const TRANSPORTATION_MODE mode)
//{
//	if (mode == TRANSPORTATION_MODE::CAR)
//		return std::make_unique<CarPathCalculator>();
//	if (mode == TRANSPORTATION_MODE::BIKE)
//		return std::make_unique<BikePathCalculator>();
//	if (mode == TRANSPORTATION_MODE::TRAIN)
//		return std::make_unique<TrainPathCalculator>();
//	if (mode == TRANSPORTATION_MODE::WALK)
//		return std::make_unique<WalkPathCalculator>();
//	if (mode == TRANSPORTATION_MODE::PUBLIC_TRANSPORTATION)
//		return std::make_unique<PublicTransportationPathCalculator>();
//	return nullptr;
//}
