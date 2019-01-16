#ifndef _CUST_BATTERY_METER_TABLE_H
#define _CUST_BATTERY_METER_TABLE_H

#include <mach/mt_typedefs.h>

// ============================================================
// define
// ============================================================
#define BAT_NTC_10 0
#define BAT_NTC_47 0
//cx861 add
#define BAT_NTC_68 1     
#if (BAT_NTC_10 == 1)
#define RBAT_PULL_UP_R             24000	
#endif

#if (BAT_NTC_47 == 1)
#define RBAT_PULL_UP_R             61900	
#endif
//cx861 add
#if (BAT_NTC_68 == 1)
#define RBAT_PULL_UP_R             68000	
#endif
#define RBAT_PULL_UP_VOLT          2800

/* multiple battery profile compile options */
#define MTK_GET_BATTERY_ID_BY_AUXADC
#define BATTERY_ID_CHANNEL_NUM      7//3
#define TOTAL_BATTERY_NUMBER        2//4
/*#define MTK_GET_BATTERY_ID_BY_GPIO*/

// ============================================================
// ENUM
// ============================================================

// ============================================================
// structure
// ============================================================

// ============================================================
// typedef
// ============================================================
typedef struct _BATTERY_PROFILE_STRUC
{
    kal_int32 percentage;
    kal_int32 voltage;
} BATTERY_PROFILE_STRUC, *BATTERY_PROFILE_STRUC_P;

typedef struct _R_PROFILE_STRUC
{
    kal_int32 resistance; // Ohm
    kal_int32 voltage;
} R_PROFILE_STRUC, *R_PROFILE_STRUC_P;

typedef enum
{
    T1_0C,
    T2_25C,
    T3_50C
} PROFILE_TEMPERATURE;

// ============================================================
// External Variables
// ============================================================

// ============================================================
// External function
// ============================================================

// ============================================================
// <DOD, Battery_Voltage> Table
// ============================================================

/* Qmax for battery  */
kal_int32 g_Q_MAX_POS_50[TOTAL_BATTERY_NUMBER] = {4016, 4072};
kal_int32 g_Q_MAX_POS_25[TOTAL_BATTERY_NUMBER] = {4062,4065};
kal_int32 g_Q_MAX_POS_0[TOTAL_BATTERY_NUMBER] = {3741,3705};
kal_int32 g_Q_MAX_NEG_10[TOTAL_BATTERY_NUMBER] = {2346,2794}; 

kal_int32 g_Q_MAX_POS_50_H_CURRENT[TOTAL_BATTERY_NUMBER] = {3936,4056};
kal_int32 g_Q_MAX_POS_25_H_CURRENT[TOTAL_BATTERY_NUMBER] = {3981,4044};
kal_int32 g_Q_MAX_POS_0_H_CURRENT[TOTAL_BATTERY_NUMBER] = {3666,3230};
kal_int32 g_Q_MAX_NEG_10_H_CURRENT[TOTAL_BATTERY_NUMBER] = {2299,1488}; 

kal_int32 g_Q_MAX_SYS_VOLTAGE[TOTAL_BATTERY_NUMBER] = {3350, 3350};
kal_int32 g_BATTERYPSEUDO1[TOTAL_BATTERY_NUMBER] = {8, 4};

kal_int32 g_battery_id_voltage[TOTAL_BATTERY_NUMBER] = {4000, 8000};//0~0.4V for battery 0, 0.4~0.8V for battery 1, 

#if (BAT_NTC_10 == 1)
    BATT_TEMPERATURE Batt_Temperature_Table[TOTAL_BATTERY_NUMBER][17] = {
    	{
			{-20,68237},
			{-15,53650},
			{-10,42506},
			{ -5,33892},
			{  0,27219},
			{  5,22021},
			{ 10,17926},
			{ 15,14674},
			{ 20,12081},
			{ 25,10000},
			{ 30,8315},
			{ 35,6948},
			{ 40,5834},
			{ 45,4917},
			{ 50,4161},
			{ 55,3535},
			{ 60,3014}
		},
		{
			{-20,68237},
			{-15,53650},
			{-10,42506},
			{ -5,33892},
			{  0,27219},
			{  5,22021},
			{ 10,17926},
			{ 15,14674},
			{ 20,12081},
			{ 25,10000},
			{ 30,8315},
			{ 35,6948},
			{ 40,5834},
			{ 45,4917},
			{ 50,4161},
			{ 55,3535},
			{ 60,3014}
		}

    };
#endif

#if (BAT_NTC_47 == 1)
    BATT_TEMPERATURE Batt_Temperature_Table[TOTAL_BATTERY_NUMBER][17] = {
    	{
			{-20,483954},
			{-15,360850},
			{-10,271697},
			{ -5,206463},
			{  0,158214},
			{  5,122259},
			{ 10,95227},
			{ 15,74730},
			{ 20,59065},
			{ 25,47000},
			{ 30,37643},
			{ 35,30334},
			{ 40,24591},
			{ 45,20048},
			{ 50,16433},
			{ 55,13539},
			{ 60,11210} 

		},
        {
			{-20,483954},
			{-15,360850},
			{-10,271697},
			{ -5,206463},
			{  0,158214},
			{  5,122259},
			{ 10,95227},
			{ 15,74730},
			{ 20,59065},
			{ 25,47000},
			{ 30,37643},
			{ 35,30334},
			{ 40,24591},
			{ 45,20048},
			{ 50,16433},
			{ 55,13539},
			{ 60,11210} 
		}

    };
#endif
//add CM865
#if (BAT_NTC_68 == 1)
    BATT_TEMPERATURE Batt_Temperature_Table[TOTAL_BATTERY_NUMBER][17] = {
    	{
    	    {-20,667700},
        	{-15,502600},
	        {-10,381700},
	        { -5,292300},
	        {  0,225400},
	        {  5,175100},
	        { 10,136900},
	        { 15,107800},
	        { 20,85350},
	        { 25,68000},
	        { 30,54500},
	        { 35,43930},
	        { 40,35610},
	        { 45,29020},
	        { 50,23770},
	        { 55,19580},
        	{ 60,16200}
 		},
        {
    	    {-20,667700},
        	{-15,502600},
	        {-10,381700},
	        { -5,292300},
	        {  0,225400},
	        {  5,175100},
	        { 10,136900},
	        { 15,107800},
	        { 20,85350},
	        { 25,68000},
	        { 30,54500},
	        { 35,43930},
	        { 40,35610},
	        { 45,29020},
	        { 50,23770},
	        { 55,19580},
        	{ 60,16200}
        }

 };
#endif

// T0 -10C
BATTERY_PROFILE_STRUC battery_profile_t0[TOTAL_BATTERY_NUMBER][90] =
{
	{
	    {0,4347},
	    {2,4309},
	    {5,4281},
	    {6,4260},
	    {8,4242},
	    {11,4225},
	    {13,4209},
	    {14,4195},
	    {17,4180},
	    {19,4166},
	    {20,4152},
	    {24,4138},
	    {25,4125},
	    {27,4111},
	    {30,4100},
	    {32,4089},
	    {34,4077},
	    {37,4063},
	    {39,4046},
	    {40,4027},
	    {43,4009},
	    {45,3992},
	    {46,3978},
	    {49,3966},
	    {51,3955},
	    {53,3944},
	    {56,3933},
	    {57,3922},
	    {59,3911},
	    {62,3900},
	    {64,3890},
	    {65,3880},
	    {68,3871},
	    {70,3862},
	    {71,3854},
	    {75,3847},
	    {76,3841},
	    {79,3834},
	    {81,3829},
	    {83,3823},
	    {86,3818},
	    {88,3813},
	    {89,3809},
	    {93,3805},
	    {94,3802},
	    {96,3799},
	    {99,3796},
	    {100,3794},
	    {102,3792},
	    {105,3789},
	    {107,3788},
	    {108,3785},
	    {111,3783},
	    {113,3780},
	    {115,3777},
	    {118,3774},
	    {119,3771},
	    {121,3766},
	    {124,3762},
	    {126,3756},
	    {127,3751},
	    {130,3744},
	    {132,3737},
	    {134,3729},
	    {137,3720},
	    {138,3711},
	    {140,3703},
	    {143,3698},
	    {145,3694},
	    {147,3691},
	    {150,3686},
	    {152,3677},
	    {153,3662},
	    {155,3644},
	    {155,3623},
	    {156,3603},
	    {156,3583},
	    {158,3565},
	    {158,3548},
	    {158,3532},
	    {158,3518},
	    {159,3504},
	    {159,3493},
	    {159,3482},
	    {159,3482},
	    {159,3482},
	    {159,3482},
	    {159,3482},
	    {159,3482},
	    {159,3482}   
	},	
	{
	    {0,4361},
	    {1,4341},
	    {3,4322},
	    {5,4305},
	    {7,4288},
	    {8,4272},
	    {10,4257},
	    {12,4242},
	    {14,4226},
	    {16,4210},
	    {17,4193},
	    {19,4173},
	    {21,4139},
	    {23,4095},
	    {25,4073},
	    {26,4055},
	    {28,4035},
	    {30,4013},
	    {32,3990},
	    {33,3970},
	    {35,3954},
	    {37,3940},
	    {39,3929},
	    {41,3920},
	    {42,3911},
	    {44,3902},
	    {46,3895},
	    {48,3887},
	    {50,3879},
	    {51,3871},
	    {53,3864},
	    {55,3856},
	    {57,3849},
	    {59,3842},
	    {60,3835},
	    {62,3828},
	    {64,3821},
	    {66,3815},
	    {67,3807},
	    {69,3800},
	    {71,3792},
	    {73,3785},
	    {75,3777},
	    {76,3769},
	    {78,3760},
	    {80,3752},
	    {82,3743},
	    {84,3735},
	    {85,3727},
	    {87,3721},
	    {89,3714},
	    {90,3709},
	    {92,3705},
	    {93,3701},
	    {93,3698},
	    {94,3694},
	    {95,3690},
	    {95,3686},
	    {96,3681},
	    {96,3677},
	    {97,3672},
	    {97,3667},
	    {97,3663},
	    {98,3658},
	    {98,3654},
	    {98,3650},
	    {98,3647},
	    {98,3644},
	    {98,3640},
	    {99,3638},
	    {99,3636},
	    {99,3633},
	    {99,3631},
	    {99,3629},
	    {99,3627},
	    {99,3625},
	    {99,3623},
	    {99,3622},
	    {99,3620},
	    {99,3619},
	    {99,3617},
	    {99,3616},
	    {99,3615},
	    {99,3613},
	    {100,3613},
	    {100,3613},
	    {100,3613},
	    {100,3613},
	    {100,3613},
	    {100,3613}
	}

};      
        
// T1 0C 
BATTERY_PROFILE_STRUC battery_profile_t1[TOTAL_BATTERY_NUMBER][90] =
{
	{
        {0,4366},
	    {1,4342},
	    {4,4324},
	    {4,4307},
	    {5,4292},
	    {6,4277},
	    {8,4262},
	    {10,4248},
	    {11,4234},
	    {12,4219},
	    {13,4205},
	    {14,4192},
	    {16,4179},
	    {18,4165},
	    {19,4152},
	    {20,4139},
	    {21,4126},
	    {23,4113},
	    {24,4100},
	    {25,4089},
	    {26,4079},
	    {29,4069},
	    {29,4056},
	    {30,4038},
	    {32,4019},
	    {34,4002},
	    {35,3987},
	    {36,3975},
	    {37,3965},
	    {39,3955},
	    {40,3944},
	    {41,3932},
	    {43,3920},
	    {44,3908},
	    {46,3896},
	    {47,3886},
	    {48,3877},
	    {49,3869},
	    {50,3861},
	    {53,3854},
	    {54,3847},
	    {54,3841},
	    {55,3835},
	    {58,3829},
	    {59,3823},
	    {60,3819},
	    {62,3814},
	    {63,3809},
	    {64,3805},
	    {65,3801},
	    {67,3797},
	    {68,3793},
	    {70,3790},
	    {71,3788},
	    {72,3786},
	    {73,3783},
	    {75,3781},
	    {76,3779},
	    {78,3776},
	    {79,3772},
	    {79,3768},
	    {82,3765},
	    {83,3760},
	    {84,3755},
	    {85,3749},
	    {87,3742},
	    {88,3734},
	    {89,3727},
	    {90,3717},
	    {93,3708},
	    {94,3701},
	    {95,3697},
	    {96,3694},
	    {97,3690},
	    {99,3685},
	    {100,3674},
	    {102,3643},
	    {103,3590},
	    {103,3555},
	    {104,3526},
	    {104,3501},
	    {104,3480},
	    {105,3462},
	    {105,3446},
	    {105,3446},
	    {105,3446},
	    {105,3446},
	    {105,3446},
	    {105,3446},
	    {105,3446}
	},
	{
	    {0,4378},
	    {1,4360},
	    {2,4342},
	    {4,4325},
	    {5,4305},
	    {6,4264},
	    {8,4218},
	    {9,4197},
	    {10,4181},
	    {12,4166},
	    {13,4152},
	    {14,4138},
	    {16,4125},
	    {17,4111},
	    {18,4097},
	    {20,4086},
	    {21,4076},
	    {22,4066},
	    {24,4052},
	    {25,4032},
	    {26,4012},
	    {28,3995},
	    {29,3982},
	    {31,3972},
	    {32,3963},
	    {33,3954},
	    {35,3944},
	    {36,3933},
	    {37,3921},
	    {39,3909},
	    {40,3897},
	    {41,3886},
	    {43,3875},
	    {44,3866},
	    {45,3858},
	    {47,3850},
	    {48,3844},
	    {49,3837},
	    {51,3831},
	    {52,3826},
	    {53,3820},
	    {55,3815},
	    {56,3811},
	    {57,3806},
	    {59,3802},
	    {60,3798},
	    {62,3794},
	    {63,3791},
	    {64,3787},
	    {66,3784},
	    {67,3782},
	    {68,3780},
	    {70,3778},
	    {71,3776},
	    {72,3773},
	    {74,3770},
	    {75,3766},
	    {76,3762},
	    {78,3758},
	    {79,3753},
	    {80,3747},
	    {82,3741},
	    {83,3734},
	    {84,3726},
	    {86,3718},
	    {87,3709},
	    {88,3702},
	    {90,3698},
	    {91,3694},
	    {93,3691},
	    {94,3685},
	    {95,3671},
	    {96,3641},
	    {97,3616},
	    {98,3593},
	    {98,3572},
	    {98,3554},
	    {99,3538},
	    {99,3524},
	    {99,3513},
	    {99,3504},
	    {99,3496},
	    {99,3489},
	    {99,3483},
	    {100,3483},
	    {100,3483},
	    {100,3483},
	    {100,3483},
	    {100,3483},
	    {100,3483}
	}
};           

// T2 25C
BATTERY_PROFILE_STRUC battery_profile_t2[TOTAL_BATTERY_NUMBER][90] =
{
	{
        {0,4387},
	    {1,4372},
	    {2,4358},
	    {4,4345},
	    {5,4331},
	    {6,4317},
	    {7,4303},
	    {9,4289},
	    {10,4275},
	    {11,4261},
	    {12,4247},
	    {13,4233},
	    {15,4219},
	    {16,4205},
	    {17,4192},
	    {18,4178},
	    {19,4164},
	    {21,4151},
	    {22,4138},
	    {23,4125},
	    {24,4112},
	    {26,4099},
	    {27,4087},
	    {28,4075},
	    {29,4065},
	    {30,4053},
	    {32,4040},
	    {33,4026},
	    {34,4012},
	    {35,4001},
	    {37,3990},
	    {38,3980},
	    {39,3969},
	    {40,3960},
	    {41,3947},
	    {43,3934},
	    {44,3919},
	    {45,3905},
	    {46,3893},
	    {48,3883},
	    {49,3875},
	    {51,3867},
	    {52,3860},
	    {53,3854},
	    {55,3847},
	    {56,3841},
	    {57,3836},
	    {58,3830},
	    {59,3825},
	    {61,3820},
	    {62,3816},
	    {63,3811},
	    {64,3807},
	    {66,3803},
	    {67,3799},
	    {68,3796},
	    {69,3792},
	    {70,3788},
	    {72,3784},
	    {73,3780},
	    {74,3775},
	    {75,3770},
	    {77,3765},
	    {78,3760},
	    {79,3755},
	    {80,3750},
	    {81,3746},
	    {83,3742},
	    {84,3736},
	    {85,3728},
	    {86,3721},
	    {87,3714},
	    {89,3705},
	    {90,3696},
	    {91,3693},
	    {92,3692},
	    {94,3691},
	    {95,3689},
	    {96,3683},
	    {97,3661},
	    {98,3608},
	    {100,3533},
	    {101,3420},
	    {102,3283},
	    {102,3283},
	    {102,3283},
	    {102,3283},
	    {102,3283},
	    {102,3283},
	    {102,3283}
	},
	{
	    {0,4383},
	    {1,4363},
	    {2,4346},
	    {3,4331},
	    {4,4316},
	    {6,4301},
	    {7,4286},
	    {8,4271},
	    {9,4256},
	    {11,4242},
	    {12,4228},
	    {13,4213},
	    {14,4199},
	    {15,4185},
	    {17,4171},
	    {18,4157},
	    {19,4143},
	    {20,4130},
	    {22,4117},
	    {23,4103},
	    {24,4090},
	    {25,4077},
	    {27,4066},
	    {28,4056},
	    {29,4043},
	    {30,4028},
	    {31,4013},
	    {33,4001},
	    {34,3992},
	    {35,3982},
	    {36,3973},
	    {38,3963},
	    {39,3953},
	    {40,3942},
	    {41,3930},
	    {43,3917},
	    {44,3903},
	    {45,3890},
	    {46,3879},
	    {47,3870},
	    {49,3861},
	    {50,3854},
	    {51,3847},
	    {52,3840},
	    {54,3834},
	    {55,3829},
	    {56,3823},
	    {57,3818},
	    {59,3814},
	    {60,3809},
	    {61,3805},
	    {62,3801},
	    {63,3797},
	    {65,3793},
	    {66,3790},
	    {67,3787},
	    {68,3784},
	    {70,3780},
	    {71,3777},
	    {72,3773},
	    {73,3769},
	    {74,3765},
	    {76,3761},
	    {77,3756},
	    {78,3751},
	    {79,3747},
	    {81,3743},
	    {82,3738},
	    {83,3731},
	    {84,3723},
	    {86,3716},
	    {87,3709},
	    {88,3698},
	    {89,3693},
	    {90,3691},
	    {92,3690},
	    {93,3688},
	    {94,3685},
	    {95,3673},
	    {97,3626},
	    {98,3559},
	    {99,3459},
	    {100,3290},
	    {100,3272},
	    {100,3272},
	    {100,3272},
	    {100,3272},
	    {100,3272},
	    {100,3272},
	    {100,3272}	    
	}
};     

// T3 50C
BATTERY_PROFILE_STRUC battery_profile_t3[TOTAL_BATTERY_NUMBER][90] =
{
	{
	    {0,4390},
	    {1,4375},
	    {2,4360},
	    {4,4347},
	    {5,4334},
	    {6,4320},
	    {7,4306},
	    {9,4292},
	    {10,4278},
	    {11,4265},
	    {12,4250},
	    {13,4236},
	    {15,4222},
	    {16,4208},
	    {17,4195},
	    {18,4181},
	    {20,4167},
	    {21,4154},
	    {22,4141},
	    {23,4128},
	    {24,4114},
	    {27,4101},
	    {28,4089},
	    {29,4076},
	    {30,4064},
	    {32,4052},
	    {33,4041},
	    {34,4029},
	    {35,4017},
	    {36,4006},
	    {38,3996},
	    {39,3985},
	    {40,3975},
	    {41,3964},
	    {42,3953},
	    {44,3941},
	    {45,3925},
	    {46,3909},
	    {47,3896},
	    {49,3887},
	    {50,3878},
	    {51,3870},
	    {52,3863},
	    {53,3856},
	    {55,3849},
	    {56,3843},
	    {57,3837},
	    {58,3831},
	    {60,3826},
	    {61,3821},
	    {62,3816},
	    {63,3811},
	    {64,3807},
	    {66,3802},
	    {67,3798},
	    {68,3794},
	    {69,3790},
	    {71,3786},
	    {72,3781},
	    {73,3774},
	    {74,3764},
	    {76,3757},
	    {78,3752},
	    {79,3746},
	    {80,3740},
	    {81,3735},
	    {83,3730},
	    {84,3726},
	    {85,3720},
	    {86,3713},
	    {87,3705},
	    {89,3698},
	    {90,3688},
	    {91,3680},
	    {92,3679},
	    {93,3678},
	    {95,3676},
	    {96,3674},
	    {97,3667},
	    {98,3638},
	    {100,3585},
	    {101,3510},
	    {102,3397},
	    {103,3260},
	    {103,3260},
	    {103,3260},
	    {103,3260},
	    {103,3260},
	    {103,3260},
	    {103,3260}
	},
	{
	    {0,4389},
	    {1,4369},
	    {2,4352},
	    {3,4336},
	    {4,4321},
	    {6,4306},
	    {7,4291},
	    {8,4276},
	    {9,4262},
	    {11,4247},
	    {12,4233},
	    {13,4218},
	    {14,4204},
	    {15,4190},
	    {17,4176},
	    {18,4162},
	    {19,4148},
	    {20,4135},
	    {22,4121},
	    {23,4108},
	    {24,4095},
	    {25,4082},
	    {27,4069},
	    {28,4056},
	    {29,4044},
	    {30,4033},
	    {31,4021},
	    {33,4010},
	    {34,3999},
	    {35,3988},
	    {36,3978},
	    {38,3967},
	    {39,3957},
	    {40,3947},
	    {41,3937},
	    {42,3926},
	    {44,3912},
	    {45,3896},
	    {46,3883},
	    {47,3873},
	    {49,3864},
	    {50,3856},
	    {51,3849},
	    {52,3842},
	    {54,3836},
	    {55,3830},
	    {56,3824},
	    {57,3819},
	    {58,3814},
	    {60,3809},
	    {61,3805},
	    {62,3800},
	    {63,3796},
	    {65,3792},
	    {66,3789},
	    {67,3785},
	    {68,3782},
	    {69,3779},
	    {71,3775},
	    {72,3767},
	    {73,3758},
	    {74,3752},
	    {76,3747},
	    {77,3741},
	    {78,3736},
	    {79,3731},
	    {81,3727},
	    {82,3722},
	    {83,3717},
	    {84,3709},
	    {85,3702},
	    {87,3695},
	    {88,3685},
	    {89,3678},
	    {90,3677},
	    {92,3676},
	    {93,3675},
	    {94,3672},
	    {95,3660},
	    {96,3618},
	    {98,3555},
	    {99,3467},
	    {100,3319},
	    {100,3319},
	    {100,3319},
	    {100,3319},
	    {100,3319},
	    {100,3319},
	    {100,3319},
	    {100,3319}
	}
};           

// battery profile for actual temperature. The size should be the same as T1, T2
BATTERY_PROFILE_STRUC battery_profile_temperature[TOTAL_BATTERY_NUMBER][90] =
{
	{
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },  
		{0  , 0 }, 
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },  
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 }
	},
	{
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },	
		{0	, 0 }, 
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },	
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0	, 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 }
	}
};

// ============================================================
// <Rbat, Battery_Voltage> Table
// ============================================================
// T0 -10C
R_PROFILE_STRUC r_profile_t0[TOTAL_BATTERY_NUMBER][90] =
{
	{
	    {845 ,4347},
	    {845 ,4309},
	    {895 ,4281},
	    {920 ,4260},
	    {933 ,4242},
	    {938 ,4225},
	    {938 ,4209},
	    {940 ,4195},
	    {938 ,4180},
	    {940 ,4166},
	    {943 ,4152},
	    {940 ,4138},
	    {940 ,4125},
	    {938 ,4111},
	    {940 ,4100},
	    {943 ,4089},
	    {945 ,4077},
	    {943 ,4063},
	    {935 ,4046},
	    {928 ,4027},
	    {915 ,4009},
	    {910 ,3992},
	    {905 ,3978},
	    {903 ,3966},
	    {903 ,3955},
	    {900 ,3944},
	    {895 ,3933},
	    {888 ,3922},
	    {885 ,3911},
	    {878 ,3900},
	    {878 ,3890},
	    {873 ,3880},
	    {873 ,3871},
	    {870 ,3862},
	    {870 ,3854},
	    {873 ,3847},
	    {880 ,3841},
	    {880 ,3834},
	    {883 ,3829},
	    {878 ,3823},
	    {868 ,3818},
	    {860 ,3813},
	    {850 ,3809},
	    {838 ,3805},
	    {823 ,3802},
	    {810 ,3799},
	    {793 ,3796},
	    {790 ,3794},
	    {798 ,3792},
	    {803 ,3789},
	    {815 ,3788},
	    {823 ,3785},
	    {833 ,3783},
	    {833 ,3780},
	    {823 ,3777},
	    {815 ,3774},
	    {813 ,3771},
	    {808 ,3766},
	    {810 ,3762},
	    {810 ,3756},
	    {815 ,3751},
	    {823 ,3744},
	    {830 ,3737},
	    {840 ,3729},
	    {850 ,3720},
	    {865 ,3711},
	    {883 ,3703},
	    {910 ,3698},
	    {940 ,3694},
	    {983 ,3691},
	    {1048,3686},
	    {1125,3677},
	    {1155,3662},
	    {1110,3644},
	    {1058,3623},
	    {1008,3603},
	    {960 ,3583},
	    {915 ,3565},
	    {870 ,3548},
	    {833 ,3532},
	    {798 ,3518},
	    {763 ,3504},
	    {733 ,3493},
	    {710 ,3482},
	    {705 ,3482},
	    {705 ,3482},
	    {705 ,3482},
	    {705 ,3482},
	    {705 ,3482},
	    {705 ,3482}
	},
	{
	    {735,4361},
	    {735,4341},
	    {755,4322},
	    {767,4305},
	    {770,4288},
	    {775,4272},
	    {775,4257},
	    {780,4242},
	    {780,4226},
	    {785,4210},
	    {792,4193},
	    {807,4173},
	    {850,4139},
	    {1032,4095},
	    {1137,4073},
	    {1167,4055},
	    {1167,4035},
	    {1160,4013},
	    {1152,3990},
	    {1150,3970},
	    {1152,3954},
	    {1150,3940},
	    {1157,3929},
	    {1155,3920},
	    {1157,3911},
	    {1155,3902},
	    {1157,3895},
	    {1162,3887},
	    {1165,3879},
	    {1160,3871},
	    {1165,3864},
	    {1165,3856},
	    {1170,3849},
	    {1172,3842},
	    {1172,3835},
	    {1175,3828},
	    {1177,3821},
	    {1185,3815},
	    {1185,3807},
	    {1190,3800},
	    {1192,3792},
	    {1197,3785},
	    {1200,3777},
	    {1202,3769},
	    {1205,3760},
	    {1212,3752},
	    {1215,3743},
	    {1222,3735},
	    {1232,3727},
	    {1250,3721},
	    {1267,3714},
	    {1272,3709},
	    {1262,3705},
	    {1252,3701},
	    {1247,3698},
	    {1235,3694},
	    {1227,3690},
	    {1217,3686},
	    {1202,3681},
	    {1195,3677},
	    {1180,3672},
	    {1167,3667},
	    {1157,3663},
	    {1145,3658},
	    {1135,3654},
	    {1125,3650},
	    {1117,3647},
	    {1110,3644},
	    {1102,3640},
	    {1095,3638},
	    {1090,3636},
	    {1085,3633},
	    {1080,3631},
	    {1075,3629},
	    {1070,3627},
	    {1065,3625},
	    {1060,3623},
	    {1057,3622},
	    {1052,3620},
	    {1050,3619},
	    {1047,3617},
	    {1040,3616},
	    {1040,3615},
	    {1037,3613},
	    {1035,3613},
	    {1035,3613},
	    {1035,3613},
	    {1035,3613},
	    {1035,3613},
	    {1035,3613}
	}
};      

// T1 0C
R_PROFILE_STRUC r_profile_t1[TOTAL_BATTERY_NUMBER][90] =
{
	{
	    {425,4366},
	    {425,4342},
	    {438,4324},
	    {443,4307},
	    {445,4292},
	    {448,4277},
	    {448,4262},
	    {450,4248},
	    {453,4234},
	    {450,4219},
	    {450,4205},
	    {453,4192},
	    {455,4179},
	    {455,4165},
	    {455,4152},
	    {458,4139},
	    {460,4126},
	    {460,4113},
	    {460,4100},
	    {465,4089},
	    {475,4079},
	    {483,4069},
	    {483,4056},
	    {475,4038},
	    {468,4019},
	    {465,4002},
	    {465,3987},
	    {465,3975},
	    {468,3965},
	    {468,3955},
	    {460,3944},
	    {453,3932},
	    {445,3920},
	    {440,3908},
	    {435,3896},
	    {433,3886},
	    {433,3877},
	    {433,3869},
	    {433,3861},
	    {435,3854},
	    {438,3847},
	    {440,3841},
	    {443,3835},
	    {443,3829},
	    {445,3823},
	    {450,3819},
	    {455,3814},
	    {455,3809},
	    {460,3805},
	    {465,3801},
	    {468,3797},
	    {468,3793},
	    {473,3790},
	    {480,3788},
	    {485,3786},
	    {488,3783},
	    {495,3781},
	    {503,3779},
	    {513,3776},
	    {515,3772},
	    {523,3768},
	    {533,3765},
	    {540,3760},
	    {553,3755},
	    {565,3749},
	    {578,3742},
	    {588,3734},
	    {605,3727},
	    {620,3717},
	    {640,3708},
	    {660,3701},
	    {688,3697},
	    {720,3694},
	    {755,3690},
	    {808,3685},
	    {868,3674},
	    {928,3643},
	    {975,3590},
	    {890,3555},
	    {818,3526},
	    {753,3501},
	    {703,3480},
	    {655,3462},
	    {618,3446},
	    {618,3446},
	    {618,3446},
	    {618,3446},
	    {618,3446},
	    {618,3446},
	    {618,3446}
	},	
	{
	    {337,4378},
	    {337,4360},
	    {342,4342},
	    {345,4325},
	    {350,4305},
	    {357,4264},
	    {490,4218},
	    {527,4197},
	    {532,4181},
	    {535,4166},
	    {537,4152},
	    {540,4138},
	    {545,4125},
	    {545,4111},
	    {545,4097},
	    {550,4086},
	    {557,4076},
	    {565,4066},
	    {567,4052},
	    {562,4032},
	    {560,4012},
	    {560,3995},
	    {562,3982},
	    {567,3972},
	    {572,3963},
	    {575,3954},
	    {572,3944},
	    {570,3933},
	    {565,3921},
	    {562,3909},
	    {557,3897},
	    {555,3886},
	    {552,3875},
	    {555,3866},
	    {555,3858},
	    {560,3850},
	    {565,3844},
	    {565,3837},
	    {567,3831},
	    {570,3826},
	    {575,3820},
	    {580,3815},
	    {585,3811},
	    {587,3806},
	    {590,3802},
	    {595,3798},
	    {597,3794},
	    {605,3791},
	    {607,3787},
	    {610,3784},
	    {615,3782},
	    {620,3780},
	    {627,3778},
	    {632,3776},
	    {640,3773},
	    {645,3770},
	    {652,3766},
	    {662,3762},
	    {672,3758},
	    {685,3753},
	    {700,3747},
	    {715,3741},
	    {730,3734},
	    {747,3726},
	    {767,3718},
	    {787,3709},
	    {812,3702},
	    {842,3698},
	    {880,3694},
	    {930,3691},
	    {992,3685},
	    {1060,3671},
	    {1102,3641},
	    {1042,3616},
	    {985,3593},
	    {930,3572},
	    {885,3554},
	    {845,3538},
	    {812,3524},
	    {782,3513},
	    {762,3504},
	    {742,3496},
	    {722,3489},
	    {707,3483},
	    {710,3483}, 
	    {710,3483}, 
	    {710,3483}, 
	    {710,3483}, 
	    {710,3483}, 
	    {710,3483}
	}

};

// T2 25C
R_PROFILE_STRUC r_profile_t2[TOTAL_BATTERY_NUMBER][90] =
{
	{
        {125,4387},
	    {125,4372},
	    {125,4358},
	    {125,4345},
	    {125,4331},
	    {125,4317},
	    {125,4303},
	    {125,4289},
	    {125,4275},
	    {125,4261},
	    {125,4247},
	    {125,4233},
	    {125,4219},
	    {125,4205},
	    {128,4192},
	    {128,4178},
	    {125,4164},
	    {128,4151},
	    {130,4138},
	    {130,4125},
	    {133,4112},
	    {133,4099},
	    {135,4087},
	    {135,4075},
	    {140,4065},
	    {143,4053},
	    {143,4040},
	    {145,4026},
	    {145,4012},
	    {148,4001},
	    {150,3990},
	    {153,3980},
	    {153,3969},
	    {155,3960},
	    {148,3947},
	    {145,3934},
	    {135,3919},
	    {125,3905},
	    {120,3893},
	    {118,3883},
	    {118,3875},
	    {115,3867},
	    {115,3860},
	    {118,3854},
	    {115,3847},
	    {118,3841},
	    {120,3836},
	    {118,3830},
	    {118,3825},
	    {120,3820},
	    {123,3816},
	    {123,3811},
	    {123,3807},
	    {125,3803},
	    {125,3799},
	    {128,3796},
	    {128,3792},
	    {128,3788},
	    {128,3784},
	    {125,3780},
	    {123,3775},
	    {120,3770},
	    {120,3765},
	    {120,3760},
	    {118,3755},
	    {118,3750},
	    {120,3746},
	    {120,3742},
	    {120,3736},
	    {120,3728},
	    {120,3721},
	    {123,3714},
	    {123,3705},
	    {120,3696},
	    {120,3693},
	    {123,3692},
	    {130,3691},
	    {135,3689},
	    {140,3683},
	    {138,3661},
	    {138,3608},
	    {148,3533},
	    {170,3420},
	    {210,3283},
	    {210,3283},
	    {210,3283},
	    {210,3283},
	    {210,3283},
	    {210,3283},
	    {210,3283}
	},	
	{
	    {127,4383},
	    {127,4363},
	    {127,4346},
	    {127,4331},
	    {127,4316},
	    {127,4301},
	    {127,4286},
	    {127,4271},
	    {127,4256},
	    {127,4242},
	    {130,4228},
	    {130,4213},
	    {130,4199},
	    {130,4185},
	    {132,4171},
	    {132,4157},
	    {132,4143},
	    {135,4130},
	    {137,4117},
	    {137,4103},
	    {140,4090},
	    {140,4077},
	    {145,4066},
	    {152,4056},
	    {150,4043},
	    {150,4028},
	    {150,4013},
	    {155,4001},
	    {157,3992},
	    {157,3982},
	    {160,3973},
	    {160,3963},
	    {160,3953},
	    {160,3942},
	    {155,3930},
	    {147,3917},
	    {140,3903},
	    {132,3890},
	    {127,3879},
	    {125,3870},
	    {122,3861},
	    {122,3854},
	    {122,3847},
	    {120,3840},
	    {122,3834},
	    {122,3829},
	    {122,3823},
	    {125,3818},
	    {127,3814},
	    {127,3809},
	    {127,3805},
	    {130,3801},
	    {130,3797},
	    {130,3793},
	    {132,3790},
	    {135,3787},
	    {135,3784},
	    {132,3780},
	    {135,3777},
	    {132,3773},
	    {130,3769},
	    {127,3765},
	    {127,3761},
	    {125,3756},
	    {125,3751},
	    {125,3747},
	    {127,3743},
	    {127,3738},
	    {127,3731},
	    {125,3723},
	    {127,3716},
	    {130,3709},
	    {125,3698},
	    {125,3693},
	    {127,3691},
	    {132,3690},
	    {137,3688},
	    {147,3685},
	    {155,3673},
	    {142,3626},
	    {155,3559},
	    {170,3459},
	    {225,3290},
	    {180,3272},
	    {182,3272},
	    {182,3272},
	    {182,3272},
	    {182,3272},
	    {182,3272},
	    {182,3272}        
	}
}; 

// T3 50C
R_PROFILE_STRUC r_profile_t3[TOTAL_BATTERY_NUMBER][90] =
{
	{
	    {95 ,4390},
	    {95 ,4375},
	    {93 ,4360},
	    {95 ,4347},
	    {95 ,4334},
	    {95 ,4320},
	    {93 ,4306},
	    {93 ,4292},
	    {93 ,4278},
	    {98 ,4265},
	    {95 ,4250},
	    {95 ,4236},
	    {95 ,4222},
	    {95 ,4208},
	    {98 ,4195},
	    {95 ,4181},
	    {95 ,4167},
	    {98 ,4154},
	    {98 ,4141},
	    {100,4128},
	    {98 ,4114},
	    {98 ,4101},
	    {100,4089},
	    {100,4076},
	    {100,4064},
	    {100,4052},
	    {103,4041},
	    {103,4029},
	    {103,4017},
	    {105,4006},
	    {108,3996},
	    {108,3985},
	    {110,3975},
	    {113,3964},
	    {115,3953},
	    {115,3941},
	    {105,3925},
	    {98 ,3909},
	    {95 ,3896},
	    {95 ,3887},
	    {93 ,3878},
	    {93 ,3870},
	    {95 ,3863},
	    {93 ,3856},
	    {93 ,3849},
	    {93 ,3843},
	    {93 ,3837},
	    {95 ,3831},
	    {95 ,3826},
	    {98 ,3821},
	    {98 ,3816},
	    {98 ,3811},
	    {100,3807},
	    {98 ,3802},
	    {100,3798},
	    {103,3794},
	    {103,3790},
	    {103,3786},
	    {103,3781},
	    {100,3774},
	    {93 ,3764},
	    {95 ,3757},
	    {95 ,3752},
	    {95 ,3746},
	    {95 ,3740},
	    {95 ,3735},
	    {93 ,3730},
	    {98 ,3726},
	    {98 ,3720},
	    {95 ,3713},
	    {95 ,3705},
	    {95 ,3698},
	    {93 ,3688},
	    {90 ,3680},
	    {95 ,3679},
	    {98 ,3678},
	    {103,3676},
	    {110,3674},
	    {115,3667},
	    {103,3638},
	    {110,3585},
	    {115,3510},
	    {128,3397},
	    {150,3260},
	    {153,3260},
	    {153,3260},
	    {153,3260},
	    {153,3260},
	    {153,3260},
	    {153,3260}
	},	
	{
	    {95,4389},
	    {95,4369},
	    {95,4352},
	    {92,4336},
	    {95,4321},
	    {95,4306},
	    {95,4291},
	    {92,4276},
	    {95,4262},
	    {95,4247},
	    {95,4233},
	    {95,4218},
	    {95,4204},
	    {97,4190},
	    {97,4176},
	    {100,4162},
	    {97,4148},
	    {100,4135},
	    {100,4121},
	    {100,4108},
	    {102,4095},
	    {102,4082},
	    {102,4069},
	    {102,4056},
	    {102,4044},
	    {107,4033},
	    {107,4021},
	    {110,4010},
	    {110,3999},
	    {112,3988},
	    {115,3978},
	    {112,3967},
	    {117,3957},
	    {117,3947},
	    {120,3937},
	    {120,3926},
	    {112,3912},
	    {102,3896},
	    {97,3883},
	    {97,3873},
	    {95,3864},
	    {95,3856},
	    {95,3849},
	    {92,3842},
	    {95,3836},
	    {95,3830},
	    {95,3824},
	    {97,3819},
	    {97,3814},
	    {97,3809},
	    {100,3805},
	    {100,3800},
	    {100,3796},
	    {102,3792},
	    {105,3789},
	    {105,3785},
	    {107,3782},
	    {107,3779},
	    {107,3775},
	    {100,3767},
	    {95,3758},
	    {97,3752},
	    {97,3747},
	    {95,3741},
	    {97,3736},
	    {95,3731},
	    {97,3727},
	    {97,3722},
	    {100,3717},
	    {97,3709},
	    {97,3702},
	    {100,3695},
	    {95,3685},
	    {92,3678},
	    {97,3677},
	    {100,3676},
	    {107,3675},
	    {115,3672},
	    {115,3660},
	    {105,3618},
	    {110,3555},
	    {120,3467},
	    {140,3319},
	    {140,3319}, 
	    {140,3319}, 
	    {140,3319}, 
	    {140,3319}, 
	    {140,3319}, 
	    {140,3319}, 
	    {140,3319} 
	}
}; 

// r-table profile for actual temperature. The size should be the same as T1, T2 and T3
R_PROFILE_STRUC r_profile_temperature[TOTAL_BATTERY_NUMBER][90] =
{
	{
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },  
		{0  , 0 }, 
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },  
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 }
	},	
	{
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },  
		{0  , 0 }, 
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },  
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 },
		{0  , 0 }
	}
};

// ============================================================
// function prototype
// ============================================================
int fgauge_get_saddles(void);
BATTERY_PROFILE_STRUC_P fgauge_get_profile(kal_uint32 temperature);

int fgauge_get_saddles_r_table(void);
R_PROFILE_STRUC_P fgauge_get_profile_r_table(kal_uint32 temperature);

#endif	//#ifndef _CUST_BATTERY_METER_TABLE_H
