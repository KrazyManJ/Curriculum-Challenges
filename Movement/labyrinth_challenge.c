#pragma config(StandardModel, "RVW REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#define SPEED 100


void ride(int time,int targetDeg = 0){
	clearTimer(T1);
	while(time1[T1]<time){
		int g = SensorValue(gyro)-targetDeg;
		motor(leftMotor) = SPEED-g*2;
		motor(rightMotor) = SPEED+g*2;
	}
}

task main()
{
	ride(2250);
	ride(2500,-900);
	ride(2250);
	ride(2000,900);
}