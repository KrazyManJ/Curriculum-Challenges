#pragma config(StandardModel, "RVW REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define SPEED 50
#define FRONT_ANGLE 0
#define NO_SCAN_DRIVE_TIME 1000
#define BACK_ANGLE 1800
#define BLACK_LIGHT_VAL 40


void go(int angle = FRONT_ANGLE, int time = 1){
	clearTimer(T1);
	while (time1(T1) < time){
		int g = SensorValue(gyro)-angle;
		motor(leftMotor) = SPEED-g*2;
		motor(rightMotor) = SPEED+g*2;
	}
}


task main()
{
	int cycle = 1;
	while (true){
		for (int i = 0; i < cycle; i++){
			go(FRONT_ANGLE,NO_SCAN_DRIVE_TIME);
			while(SensorValue(light)>BLACK_LIGHT_VAL) go();
		}
		for (int i = 0; i < cycle; i++){
			go(BACK_ANGLE,NO_SCAN_DRIVE_TIME);
			while(SensorValue(light)>BLACK_LIGHT_VAL) go(BACK_ANGLE);
		}
		cycle++;
	}
}
