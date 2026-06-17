#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu1;

int ax, ay, az, gx, gy, gz;
float a_roll, a_pitch, g_roll, g_pitch, g_yaw, roll, pitch;

unsigned long prevTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin();
  mpu1.initialize();

  if (mpu1.testConnection()) {
    Serial.println("connection succeeded");
  }else{
    Serial.println("connection failed");
  }

  // mpu1.CalibrateAccel(6);
  // mpu1.CalibrateGyro(6);

  prevTime = micros();
}

void loop() {
  // put your main code here, to run repeatedly:
  mpu1.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  float ax_g = ax / 16384.0;
  float ay_g = ay / 16384.0;
  float az_g = az / 16384.0;

  float gx_dps = gx / 131.0;
  float gy_dps = gy / 131.0;
  float gz_dps = gz / 131.0;

  a_roll = atan(ay_g / sqrt(ax_g * ax_g + az_g * az_g)) * 180.0 / PI;
  a_pitch = atan(-ax_g / sqrt(ay_g * ay_g + az_g * az_g)) * 180.0 / PI;

  unsigned long now = micros();
  float dt = (now - prevTime) / 1000000.0;
  prevTime = now;

  g_roll = g_roll + gx_dps * dt;
  g_pitch = g_pitch + gy_dps * dt;
  g_yaw = g_yaw + gz_dps * dt;

  roll = 0.98 * (roll + gx_dps * dt) + 0.02 * a_roll;
  pitch = 0.98 * (pitch + gy_dps * dt) + 0.02 * a_pitch;

  Serial.print(roll);
  Serial.print(", ");
  Serial.print(pitch);
  Serial.print(", ");
  Serial.println(g_yaw);
 
  delay(50);

}


