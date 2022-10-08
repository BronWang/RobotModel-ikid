#ifndef ROBOTMODEL
#define ROBOTMODEL
#define DEBUG 0
#define WRITETXT 1
#define SWING_ARM 1
#define PART_NUMBER 26
#define NONE_JOINT  255
#define PI  3.1415926
// �����˹ؽ����,������ݵ�λ���Ի�����λΪ����
typedef struct robotLink {
	unsigned int linkID;    // ����ı�� linkId
	const char *name;          // �������� name
	unsigned int sister;    // �������˵ı�� sister
	unsigned int child;     // �����˵ı�� child
	unsigned int mother;    // ĸ���˵ı�� mother
	double p[3];                  // ����������ϵ�е�λ�� p
	double R[3][3];               // ����������ϵ�е���̬ R
	double v[3];               // ����������ϵ�е��ٶ� v
	double w[3];				// ����������ϵ�еĽ��ٶ� w
	double q;					// �ؽڽ� q
	double dq;					// �ؽ��ٶ� dq
	double ddq;				// �ؽڽǼ��ٶ� ddq
	double a[3];				// �ؽ���ʸ���������ĸ���ˣ� a
	double b[3];				// ���λ�ã������ĸ���ˣ� b
	double m;			// ���� m
	double c[3];				// ����λ�ã������˾ֲ�����ϵ�У� c
	double I[3][3];				// ���������������˾ֲ�����ϵ�У� I
}robotLink;					
				
enum {
	MAIN_BODY = 0,
	HEAD,
	FRONT_NECK_SWING,
	NECK_ROTATION,
	RIGHT_ARM_FRONT_SWING,
	RIGHT_ARM_SIDE_SWING,
	RIGHT_ARM_ELBOW_FRONT_SWING,
	RIGHT_HAND,
	LEFT_ARM_FRONT_SWING,
	LEFT_ARM_SIDE_SWING,
	LEFT_ARM_ELBOW_FRONT_SWING,
	LEFT_HAND,
	RIGHT_HIP_FRONT_SWING,
	RIGHT_HIP_SIDE_SWING,
	RIGHT_HIP_ROTATION,
	RIGHT_KNEE_FRONT_SWING,
	RIGHT_ANKLE_FRONT_SWING,
	RIGHT_ANKLE_SIDE_SWING,
	RIGHT_FOOT,
	LEFT_HIP_FRONT_SWING,
	LEFT_HIP_SIDE_SWING,
	LEFT_HIP_ROTATION,
	LEFT_KNEE_FRONT_SWING,
	LEFT_ANKLE_FRONT_SWING,
	LEFT_ANKLE_SIDE_SWING,
	LEFT_FOOT
};
// 20���ؽڣ�һ�����壬�����ֶˣ������Ŷˣ�һ��ͷ������26������
// id 0 ����
// id 1 ͷ��
// id 2 ��ǰ��          ��ʼλ��2048    ��2048-2844��
// id 3 ����ת			��ʼλ��2048    ˳1024-3096��
// id 4 �Ҵ��ǰ��	    ��ʼλ��2048    ��1024-3096ǰ
// id 5 �Ҵ�۲��	    ��ʼλ��1024    ��1024-3096��
// id 6 �ұ���ǰ��	    ��ʼλ��2048    ��2048-3593ǰ
// id 7 ���ֶ�			
// id 8 ����ǰ��	    ��ʼλ��2048    ǰ1024-3096��
// id 9 ���۲��	    ��ʼλ��3096    ��1024-3096��
// id 10 �����ǰ��	    ��ʼλ��2048    ǰ747-2048��
// id 11 ���ֶ�		    
// id 12 ����ǰ��		��ʼλ��2048    ��1536-2560ǰ
// id 13 ���Ų��		��ʼλ��2048    ��1712-2165��
// id 14 ������ת		��ʼλ��2048    ˳1712-2280��
// id 15 ��ϥǰ��		��ʼλ��2048    ��1024-3096ǰ
// id 16 ����ǰ��		��ʼλ��2048    ��1376-2851��
// id 17 ���ײ��		��ʼλ��2048    ��1536-2560��
// id 18 �ҽŶ�		    
// id 19 ����ǰ��		��ʼλ��2048    ǰ1536-2560��
// id 20 ���Ų��		��ʼλ��2048    ��1712-2165��
// id 21 ������ת		��ʼλ��2048    ˳1712-2280��
// id 22 ��ϥǰ��		��ʼλ��2048    ǰ1024-3096��
// id 23 ����ǰ��		��ʼλ��2048    ��1376-2851��
// id 24 ���ײ��		��ʼλ��2048    ��1536-2560��
// id 25 ��Ŷ�		    
void robotModelInit(robotLink*); // �Ѳ���
void robotStart(); // �Ѳ���
void MatrixSquare3x3(double a[3][3], double a_square[3][3]); // �Ѳ���
void MatrixMultiMatrix3x3(double a[3][3], double b[3][3], double result[3][3]); // �Ѳ���
void MatrixMultiVector3x1(double a[3][3], double b[3], double result[3]); // �Ѳ���
void VectorAddVector3x1(double a[3], double b[3], double result[3]); // �Ѳ���
void invMatrix3x3(double matrix[3][3], double result[3][3]);// �Ѳ���
void MatrixMultiVector6x1(double a[6][6], double b[6], double result[6]);
void matrix_inverse_LU(double a[6][6] ,double a_inverse[6][6]);// ���õ��������ã�ֱ��ʹ��matlab_inv
void LU_decomposition(double arr[6][6], double W_n[6][6]); // ���õ��������ã�ֱ��ʹ��matlab_inv
bool sign(double value); 
double norm(double a[], int m, int n);
void rodrigues(double* a, double q, double R[3][3]); // �Ѳ���
void rot2omega(double a[3][3], double omega[3]); // �Ѳ���
void forwardKinematics(unsigned int linkID); // �Ѳ���
double totalMass(unsigned int linkID);
void Ryaw(double q, double result[3][3]); // �Ѳ���
void Rroll(double q, double result[3][3]);// �Ѳ���
void Rpitch(double q, double result[3][3]);// �Ѳ���
void rpy2rot(double r, double p, double y, double result[3][3]);// �Ѳ��ԣ��ǶȾ�Ϊ���ȱ�ʾ
void cross3x1(double a[3], double b[3], double result[3]);  // �Ѳ���
void ForwardVelocity(unsigned int linkID);
void CalcP(unsigned int linkID, double P[3]);
void R_T3x3(double R[3][3], double R_T[3][3]);
void CalcL(unsigned int linkID, double L[3]);
void Calc_mc(unsigned int linkID, double mc[3]); // �Ѳ���
void Calc_com(double com[3]);// �Ѳ���
void changeFoot();
void angleLimit();
void waistPosition_com(double r, double p, double y, int current_frame_count);
void inverseKinmatics_head(); //�Ѳ���
void inverseKinmatics_leftHand(); //�Ѳ��ԣ��������˽���������ֵ�����������Ե�������������߾���
void inverseKinmatics_rightHand();//�Ѳ��ԣ��������˽���������ֵ�����������Ե�������������߾���
void inverseKinmatics_leftFoot(double r, double p, double y); //�Ѳ��ԣ��������˽���������ֵ�����������Ե�������������߾���,ʵ����Ҫ���������׹ؽڵ������λ�ˣ������ͨ���㲿�������λ�����
void inverseKinmatics_rightFoot(double r, double p, double y);//�Ѳ��ԣ��������˽���������ֵ�����������Ե�������������߾���,ʵ����Ҫ���������׹ؽڵ������λ�ˣ������ͨ���㲿�������λ�����
void clearTxt(); // ֻ�Ƿ����Լ����������matlab���ӻ���
void writeTxt(); // ֻ�Ƿ����Լ����������matlab���ӻ���
void trajPlan(); // �Ѳ���
void anglePlan(double delta); // �Ѳ���
void CalcTrajectory_Com(int current_frame_count);
//void test();
//void test2();
//void test3();

#endif // !ROBOTMODEL

