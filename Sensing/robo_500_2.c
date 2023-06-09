#pragma config(StandardModel, "RVW REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define SPEED 60
#define GO_BACKWARDS_TIME 200
#define DEGREE_MULTIPLIER 900


void go(int deg, bool backward = false, int time = 1){
	clearTimer(T1);
	while(time1(T1) < time){
		int g = SensorValue(gyro)-deg;
		motor(leftMotor) = (backward ? -1 : 1)*SPEED-2*g;
		motor(rightMotor) = (backward ? -1 : 1)*SPEED+2*g;
	}
}


task main(){
	int curDeg = 0;
	while (true){
		while (SensorValue(touch) == 0) go(curDeg);
		go(curDeg, true, GO_BACKWARDS_TIME);
		curDeg+=DEGREE_MULTIPLIER;
	}
}
