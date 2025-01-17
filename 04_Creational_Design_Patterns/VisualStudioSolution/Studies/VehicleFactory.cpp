#include "VehicleFactory.h"
#include "ConcreteVehicles.h"

std::unique_ptr<Vehicle> CarFactory::CreateVehicle() const {
	return std::make_unique<Car>();
}

std::unique_ptr<Vehicle> BuggyFactory::CreateVehicle() const {
	return std::make_unique<Buggy>();
}

std::unique_ptr<Vehicle> MonsterTruckFactory::CreateVehicle() const {
	return std::make_unique<MonsterTruck>();
}

std::unique_ptr<Vehicle> DaciaFactory::CreateVehicle() const {
	return std::make_unique<Dacia>();
}

std::unique_ptr<Vehicle> MotorcycleFactory::CreateVehicle() const {
	return std::make_unique<Motorcycle>();
}


