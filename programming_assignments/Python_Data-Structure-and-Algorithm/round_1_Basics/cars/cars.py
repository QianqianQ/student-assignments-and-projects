class Car:

  def __init__(self, consumption, name="unregistered vehicle"):
    self.max_tank = 50
    self.tank = self.max_tank # tank is full when delivered from factory
    self.consumption = consumption # consumption of fuel in litres per one hundred kilometers
    self.mileage = 0.0
    self.id = name

  def get_mileage(self):
    return self.mileage

  def get_tank_level(self):
    return self.tank

  def drive(self, distance):
    max_distance = self.tank / self.consumption * 100
    if max_distance < distance:
      self.mileage += max_distance
      self.tank = 0
      return max_distance
    else:
      self.mileage += distance
      self.tank -= distance * self.consumption / 100
      return distance

  def refuel(self, amount):
    self.tank += min(amount, self.max_tank - self.tank)
    return self.tank

