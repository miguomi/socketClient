
#ifndef _messageHeader_hpp_
#define _messageHeader_hpp_


//结构化数据-方式1
struct DataPackage
{
	int age;
	char name[32];
};

enum CMD {
	CMD_LOGIN,
	CMD_LOGIN_RESULT,
	CMD_LOGINOUT,
	CMD_LOGINOUT_RESULT,
	CMD_NEW_USER_JOIN,
	CMD_ERROR,
	CMD_HEART_C2S,
	CMD_HEART_S2C
};

//消息头
struct DataHeader
{
	int32_t  dataLength;//数据长度
	uint16_t  cmd;
};

//命令
struct Login :public DataHeader
{
	Login() {
		dataLength = sizeof(Login);
		cmd = CMD_LOGIN;
	}
	char  userName[32];
	char  passWord[32];
};

struct LoginResult :public DataHeader
{
	LoginResult() {
		dataLength = sizeof(LoginResult);
		cmd = CMD_LOGIN_RESULT;
		result = 0;
	}
	int  result;
	char data[96];
};

struct LoginOut :public DataHeader
{
	LoginOut() {
		dataLength = sizeof(LoginOut);
		cmd = CMD_LOGINOUT;
	}
	char  userName[32];
};

struct NewUserJoin :public DataHeader
{
	NewUserJoin() {
		dataLength = sizeof(NewUserJoin);
		cmd = CMD_NEW_USER_JOIN;
		sockID = 0;
	}
	int  sockID;
};

struct LoginOutResult :public DataHeader
{
	LoginOutResult() {
		dataLength = sizeof(LoginOutResult);
		cmd = CMD_LOGINOUT_RESULT;
		result = 0;
	}
	int  result;
};

struct HeartC2S :public DataHeader
{
	HeartC2S() {
		dataLength = sizeof(HeartC2S);
		cmd = CMD_HEART_C2S;
	}
};

struct HeartS2C :public DataHeader
{
	HeartS2C() {
		dataLength = sizeof(HeartS2C);
		cmd = CMD_HEART_S2C;
	}
};

#endif // !_messageHeader_hpp_
