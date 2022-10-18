
class UltrasonicLight : public EmbeddedSystem
{

public:
  ActuatorDigital *light;
  SensorUltrasonicCM *ultrasonic;

  UltrasonicLight(String description, String author) : EmbeddedSystem(description, author){};
  void configuration(){};

  void setup()
  {
    CreatorActuatorDigital *creatorActuatorDigital = new CreatorActuatorDigital();
    this->light = creatorActuatorDigital->createComponent(13);

    CreatorUltrasonic *creatorUltrasonic = new CreatorUltrasonic();
    this->ultrasonic = creatorUltrasonic->createComponent(4, 5);
  }

  void loop()
  {
    Serial.println("loop");
    float distance = ultrasonic->read_cm();
    if (distance < 20)
    {
      light->write(LOW);
      distance = ultrasonic->read_cm();
      delay(1000);
    }
    if (distance >= 20 && distance < 30)
    {
      light->write(HIGH);
      delay(500);
      light->write(LOW);
      delay(500);
      distance = ultrasonic->read_cm();
      delay(1000);
    }
    if (distance >= 30)
    {
      light->write(HIGH);
      distance = ultrasonic->read_cm();
      delay(1000);
    }
  }

  void runUnitTests()
  {
    light->unitTest();
    ultrasonic->unitTest();
  }
};
UltrasonicLight ultrasonicLight = UltrasonicLight("sistema embarcado alerta com luz de acordo com a distância", "Sara Guimarães");
