#pragma once
#include <memory>

#include "Vehicle.h"

class VehicleFactory {
public:
    virtual ~VehicleFactory() = default;
    // The Factory Method that subclasses will override
    // to create specific vehicles.
    virtual std::unique_ptr<Vehicle> CreateVehicle() const = 0;
};

class CarFactory final : public VehicleFactory {
public:
    std::unique_ptr<Vehicle> CreateVehicle() const override;
};

class BuggyFactory final : public VehicleFactory {
public:
    std::unique_ptr<Vehicle> CreateVehicle() const override;
};

class MonsterTruckFactory final : public VehicleFactory {
public:
    std::unique_ptr<Vehicle> CreateVehicle() const override;
};

class DaciaFactory final : public VehicleFactory {
public:
    std::unique_ptr<Vehicle> CreateVehicle() const override;
};

class MotorcycleFactory final : public VehicleFactory {
public:
    std::unique_ptr<Vehicle> CreateVehicle() const override;
};