#include <stdio.h>


/*λ����pid*/

struct _pid{
	float SetSpeed;//�����趨ֵ
	float ActualSpeed;//����ʵ��ֵ
	float err;//����ƫ��ֵ
	float err_last;//������һ��ƫ��ֵ
	float Kp, Ki, Kd;//������������֡�΢��ϵ��
	float voltage;//�����ѹֵ������ִ�����ı�����
	float integral;//�������ֵ
}pid;

void PID_init(){
	printf("PID_init begin \n");
	pid.SetSpeed = 0.0;
	pid.ActualSpeed = 0.0;
	pid.err = 0.0;
	pid.err_last = 0.0;
	pid.voltage = 0.0;
	pid.integral = 0.0;
	pid.Kp = 0.2;
	pid.Ki = 0.015;
	pid.Kd = 0.2;
	printf("PID_init end \n");
}

float PID_realize(float speed){
	pid.SetSpeed = speed;
	pid.err = pid.SetSpeed - pid.ActualSpeed;
	pid.integral += pid.err;
	pid.voltage = pid.Kp*pid.err + pid.Ki*pid.integral + pid.Kd*(pid.err - pid.err_last);
	pid.err_last = pid.err;
	pid.ActualSpeed = pid.voltage*1.0;
	return pid.ActualSpeed;
}

int main(){
	printf("System begin \n");
	PID_init();
	int count = 0;
	while (count<1000)
	{
		float speed = PID_realize(100.0);
		printf("%f\n", speed);
		count++;
	}
	return 0;
}
