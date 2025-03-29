#pragma once

enum class ParkingSpotState {
   FREE,         // Spot is available.
   OCCUPIED,     // Spot is currently in use.
   RESERVED,     // Spot is reserved for a specific user/vehicle.
   MAINTENANCE,  // Spot is temporarily unavailable due to maintenance.
   BLOCKED       // Spot is blocked for external reasons.
};