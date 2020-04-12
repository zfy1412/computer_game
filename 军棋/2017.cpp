//代码版本		2017年国赛 
//本代码由沈阳航空航天大学计算机博弈协会总负责人王跃霖统一调控
//军棋组负责人佟凯所带博弈组开发维护
//代码来自哈工大开源代码,由以上成员维护 
//本代码适用于中国大学生计算机博弈大赛博弈项目2017版交互协议
//本代码仅提供交互协议的用法示范和简单AI博弈思路，开发者需自行改进完善代码参赛
//如有意见和建议请与我们尽早联系
//王跃霖	QQ：836473734
//佟凯		QQ：904674468 
/* ************************************************************************ */
/* 绀轰緥浠ｇ爜缁存姢锛氭矆闃宠埅绌鸿埅澶╁伐澶у 璁＄畻鏈哄崥寮堢爺绌剁粍				    	*/
/* 宸辨柟妫嬪瓙缂栫爜绾﹀畾:														*/
/*	a鍙镐护,b鍐涢暱,c甯堥暱,d鏃呴暱,e鍥㈤暱,f钀ラ暱,g杩為暱,h鎺掗暱,i宸ュ叺,j鍦伴浄k鐐稿脊,l鍐涙棗	*/
/* 瀵规柟鏂规瀛愮紪鐮佺害瀹�:														*/
/*	A鍙镐护,B鍐涢暱,C甯堥暱,D鏃呴暱,E鍥㈤暱,F钀ラ暱,G杩為暱,H鎺掗暱,I宸ュ叺,J鍦伴浄K鐐稿脊,L鍐涙棗	*/
/*	X鏈煡瀵规柟妫嬪瓙,0绌烘浣�													*/
/* 鏈�鍚庢洿鏂帮細2012-03-31  meixian@hrbust.edu.cn								*/
/* 鍙镐护鐨勮蛋娉� 锛�31姝ョ瀛愬敖閲忛�夋嫨杈冨皬鐨勬瀛� 锛堢鍦ㄥ繁鏂规鐩樹笂鐨勫瓙锛�	妫嬬洏鐨勮瘎浼�
韬查伩鏁屾柟鐨�31姝�	 绗竴绉嶇瀛愬け璐ワ紝閲囧彇绗簩绉嶆柟娉曪紝  鐗规畩璧版硶鐨勭敓鎴愶紙鐐稿脊  宸ュ叺锛�


/* ************************************************************************ */
#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <string.h>

using namespace std;
int huang1 = 0;
int huang2 = 0;
//int zz=0;
int qqqqqq = 0;         //璋冭瘯鏃朵娇鐢� 锛屽湪鈥�1鈥濅腑鏄剧ず鈥滅 n 姝ョ殑寮�濮嬧��
int z1 = 0, z2 = 0, z3 = 0, z4 = 0;//鍒ゆ柇宸辨柟妫嬪瓙锛屾槸鍚︿负绗竴娆¤繘琛岃惀
int Ina_step[2] = { 2,0 };  //绗竴浣嶄唬琛ㄨ皝鍏堢瀛愮殑,1涓烘垜鍏堢瀛愮殑锛�2涓烘晫鏂瑰厛纰板瓙鐨勩�傜浜屼綅琛ㄧず鏈瀛愭鏁般��
int tra = 0;
int track[100];
int jq = 0;//琛ㄧず瀵规柟鍙镐护姝诲悗瑁佸垽鍙戠粰鎴戞柟瀵规柟鍐涙浣嶇疆淇℃伅锛�1浠ｈ〃绗竴娆″彂閫侊紝闈�1浠ｈ〃涓嶆槸绗竴娆″彂閫�
int x11, y11, x21, y21;//璁板綍鏁屾柟涓婁竴姝ョ殑琛屾棗

int qipanfen[12][5] = {
	500 ,1000,600 ,1000,800,  //
	200 ,600 ,500 ,600 ,200,
	250 ,800 ,20  ,800 ,250,
	140 ,20  ,700 ,20  ,140,
	130 ,400 ,20  ,400 ,130,
	120 ,80  ,150 ,80  ,120,
	110 ,100 ,50 ,100 ,110,
	100 ,500 ,150  ,500 ,100,
	100 ,20  ,400 ,20  ,100,
	100 ,600 ,20  ,600 ,100,
	500 ,100 ,100 ,100 ,500,
	200 ,-1000 ,200 ,-1000 ,200 };
/* ************************************************************************ */
/* 鍑芥暟鍔熻兘锛歩,j浣嶇疆鏄惁鏈柟妫嬪瓙											*/
/* 鎺ュ彛鍙傛暟锛�																*/
/*     char cMap[12][5] 妫嬬洏灞�闈�											*/
/*     int i,j 妫嬬洏浣嶇疆琛屽垪鍙�												*/
/* 杩斿洖鍊硷細																	*/
/*     1宸辨柟妫嬪瓙锛�0绌烘浣嶆垨瀵规柟妫嬪瓙											*/
/* ************************************************************************ */
int IsMyChess(char cMap[12][5], int i, int j)
{
	if (cMap[i][j] >= 'a'&& cMap[i][j] <= 'l')
		return 1;
	else
		return 0;
}

/* ************************************************************************ */
/* 鍑芥暟鍔熻兘锛歩,j浣嶇疆鏄惁鏈柟鍙Щ鍔ㄧ殑妫嬪瓙									*/
/* 鎺ュ彛鍙傛暟锛�																*/
/*     char cMap[12][5] 妫嬬洏灞�闈�											*/
/*     int i,j 妫嬬洏浣嶇疆琛屽垪鍙�												*/
/* 杩斿洖鍊硷細																	*/
/*     1宸辨柟鍙Щ鍔ㄦ瀛�(鍙镐护,鍐涢暱,...,宸ュ叺,鐐稿脊)锛�0鍐涙棗,鍦伴浄,瀵规柟妫嬪瓙鎴栫┖妫嬩綅*/
/* ************************************************************************ */
int IsMyMovingChess(char cMap[12][5], int i, int j)
{
	if (cMap[i][j] >= 'a' && cMap[i][j] <= 'i' || cMap[i][j] == 'k')
		return 1;
	else
		return 0;
}

//鐢ㄤ簬璁＄畻鎴戞柟鍙Щ鍔ㄦ瀛愭�绘暟
//杩斿洖鍊� 妫嬪瓙涓暟
int MyMovingChess(char cMap[12][5])
{
	int i, j;
	int n = 0;
	int N = 0;
	for (i = 0; i < 12; i++)
		for (j = 0; j < 5; j++)
			if (cMap[i][j] >= 'a'&&cMap[i][j] <= 'i' || cMap[i][j] == 'k')
			{
				if (i == 11 && j == 1)
					;
				else if (i == 11 && j == 3)
					;
				else
					n++;
			}
	return n;
}

/* ************************************************************************ */
/* 鍑芥暟鍔熻兘锛歩,j浣嶇疆鏄惁灞辩晫鍚庣殑鍏电珯										*/
/* 鎺ュ彛鍙傛暟锛�																*/
/*     int i,j 妫嬬洏浣嶇疆琛屽垪鍙�												*/
/* 杩斿洖鍊硷細																	*/
/*     1澶勪簬灞辩晫鍚庯紝0涓嶅浜庡北鐣屽悗											*/
/* ************************************************************************ */
int IsAfterHill(int i, int j)
{
	if (i * 5 + j == 31 || i * 5 + j == 33)
		return 1;
	else
		return 0;
}

/* ************************************************************************ */
/* 鍑芥暟鍔熻兘锛歩,j浣嶇疆鏄惁琛岃惀												*/
/* 鎺ュ彛鍙傛暟锛�																*/
/*     int i,j 妫嬬洏浣嶇疆琛屽垪鍙�												*/
/* 杩斿洖鍊硷細																	*/
/*     1鏄钀ワ紝0涓嶆槸琛岃惀													*/
/* ************************************************************************ */
int IsMoveCamp(int i, int j)
{
	if (i * 5 + j == 11 || i * 5 + j == 13 || i * 5 + j == 17 || i * 5 + j == 21 || i * 5 + j == 23 || i * 5 + j == 36 || i * 5 + j == 38 || i * 5 + j == 42 || i * 5 + j == 46 || i * 5 + j == 48)
		return 1;
	else
		return 0;
}

//鍑芥暟鍔熻兘锛氬垽鏂棗瀛愭槸鍚﹀湪閾佽建涓�
//int int 锛坕锛宩锛変负妫嬬洏浣嶇疆琛屽垪鍙�
int IsRailway(int i, int j)
{
	if (i == 1 || i == 5 || i == 6 || i == 10 || ((j == 0 || j == 4) && i>0 && i<11))
		return 1;
	else
		return 0;
}
/* ************************************************************************ */
/* 鍑芥暟鍔熻兘锛歩,j浣嶇疆鏄惁鏄鎵嬫瀛�											*/
/* 鎺ュ彛鍙傛暟锛�																*/
/*     char cMap[12][5]	妫嬬洏灞�闈�											*/
/*     int i, j	妫嬬洏浣嶇疆琛屽垪鍙�												*/
/* 杩斿洖鍊硷細																	*/
/*     1瀵规墜妫嬪瓙锛�0绌烘浣嶆垨宸辨柟妫嬪瓙											*/
/* ************************************************************************ */
int IsOppChess(char cMap[12][5], int i, int j)
{
	if (cMap[i][j] >= 'A' && cMap[i][j] <= 'X')
		return 1;
	else
		return 0;
}

//鍑芥暟鍔熻兘锛歩,j浣嶇疆鏄惁灞辩晫鍓嶇殑鍏电珯
int IsBehindHill(int i, int j)
{
	if (i * 5 + j == 26 || i * 5 + j == 28)
		return 1;
	else
		return 0;
}

/* ************************************************************************ */
/* 鍑芥暟鍔熻兘锛氬伐鍏垫嫄寮殑鎼滅储                                          		*/
/* 鎺ュ彛鍙傛暟锛�																*/
/*     char cTryMap	灏濊瘯妫嬬洏灞�闈�											*/
/*     int x	妯潗鏍�														*/
/*     int y	绾靛潗鏍�														*/
/*     int iSaMove	璁板綍宸ュ叺鐨勯搧璺嚎璧版硶									*/
/*     int iNum	宸插瓨璧版硶鏁伴噺												*/
/* 杩斿洖鍊硷細	鍒濆: iNum=0															*/
/* ************************************************************************ */
int SapperRail(int iSaMove[40][2], char cTryMap[12][5], int x, int y, int iNum)
{
	int i, t;
	//鍙互鍓嶇Щ:涓嶅湪绗竴琛�,涓嶅湪灞辩晫鍚�,鍓嶆柟鏄┖,钀藉湪閾侀亾绾夸笂
	if (x>0 && !IsAfterHill(x, y) && (cTryMap[x - 1][y] == '0' || IsOppChess(cTryMap, x - 1, y)) && IsRailway(x - 1, y))
	{
		t = 0;
		for (i = 0; i <= iNum; i++)
		{
			if ((x - 1) == iSaMove[i][0] && y == iSaMove[i][1])//鏌ュ嚭閲嶅璧版硶锛岃烦鍑哄惊鐜�
				t = 1;
		}

		if (t == 0)
		{
			iNum++;
			iSaMove[iNum][0] = x - 1;
			iSaMove[iNum][1] = y;
			if (cTryMap[x - 1][y] == '0')
			{
				cTryMap[x][y] = '0';
				cTryMap[x - 1][y] = 'i';
				iNum = SapperRail(iSaMove, cTryMap, x - 1, y, iNum);
				cTryMap[x][y] = 'i';
				cTryMap[x - 1][y] = '0';
			}
		}
	}

	//鍙互宸︾Щ:涓嶅湪鏈�宸﹀垪,宸︿晶鏄┖,钀藉湪閾侀亾绾夸笂
	if (y>0 && (cTryMap[x][y - 1] == '0' || IsOppChess(cTryMap, x, y - 1)) && IsRailway(x, y - 1))
	{
		t = 0;
		for (i = 0; i <= iNum; i++)
		{
			if (x == iSaMove[i][0] && (y - 1) == iSaMove[i][1])
				t = 1;
		}

		if (t == 0)
		{
			iNum++;
			iSaMove[iNum][0] = x;
			iSaMove[iNum][1] = y - 1;
			if (cTryMap[x][y - 1] == '0')
			{
				cTryMap[x][y] = '0';
				cTryMap[x][y - 1] = 'i';
				iNum = SapperRail(iSaMove, cTryMap, x, y - 1, iNum);
				cTryMap[x][y] = 'i';
				cTryMap[x][y - 1] = '0';
			}
		}
	}

	//鍙互鍙崇Щ://涓嶅湪鏈�鍙冲垪,鍙充晶涓嶆槸宸辨柟妫嬪瓙,钀藉湪閾侀亾绾夸笂
	if (y<4 && (cTryMap[x][y + 1] == '0' || IsOppChess(cTryMap, x, y + 1)) && IsRailway(x, y + 1))
	{
		t = 0;
		for (i = 0; i <= iNum; i++)
		{
			if (x == iSaMove[i][0] && (y + 1) == iSaMove[i][1])
				t = 1;
		}

		if (t == 0)
		{
			iNum++;
			iSaMove[iNum][0] = x;
			iSaMove[iNum][1] = y + 1;
			if (cTryMap[x][y + 1] == '0')
			{
				cTryMap[x][y] = '0';
				cTryMap[x][y + 1] = 'i';
				iNum = SapperRail(iSaMove, cTryMap, x, y + 1, iNum);
				cTryMap[x][y] = 'i';
				cTryMap[x][y + 1] = '0';
			}
		}
	}

	//鍙互鍚庣Щ:涓嶅湪鏈�鍚庝竴琛�,涓嶅湪灞辩晫鍓�,鍚庢柟涓嶆槸宸辨柟妫嬪瓙,钀藉湪閾侀亾绾夸笂
	if (x<11 && !IsBehindHill(x, y) && (cTryMap[x + 1][y] == '0' || IsOppChess(cTryMap, x + 1, y)) && IsRailway(x + 1, y))
	{
		t = 0;
		for (i = 0; i <= iNum; i++)
		{
			if ((x + 1) == iSaMove[i][0] && y == iSaMove[i][1])
				t = 1;
		}

		if (t == 0)
		{
			iNum++;
			iSaMove[iNum][0] = (x + 1);
			iSaMove[iNum][1] = y;
			if (cTryMap[x + 1][y] == '0')
			{
				cTryMap[x][y] = '0';
				cTryMap[x + 1][y] = 'i';
				iNum = SapperRail(iSaMove, cTryMap, x + 1, y, iNum);
				cTryMap[x][y] = 'i';
				cTryMap[x + 1][y] = '0';
			}
		}
	}

	return iNum;
}
/* ************************************************************************ */
/* 鍑芥暟鍔熻兘锛氬垽鏂槸鏌愪釜妫嬪瓙鐨勬鐜�                                      		*/
/* 鎺ュ彛鍙傛暟锛�																*/
/*     int i													            */
/*     int j		  鎵�瑕佸垽鏂瀛愮殑浣嶇疆								    */
/*     int k		  妫嬪瓙缂栧彿  											*/
/*     int dz[25][14] 鏁屾柟妫嬪瓙姒傜巼							                */
/* ************************************************************************ */
int Judge(int i, int j, int k, int dz[25][14])
{
	for (int n = 0; n<25; n++)
	{
		if (dz[n][12] == i && dz[n][13] == j)
			return dz[n][k];
	}
	return 0;
}
/* ************************************************************************ */
/* 鍑芥暟鍔熻兘锛歩,j浣嶇疆鏄惁澶ф湰钀�											*/
/* 鎺ュ彛鍙傛暟锛�																*/
/*     int i,j 妫嬬洏浣嶇疆琛屽垪鍙�												*/
/* 杩斿洖鍊硷細																	*/
/*     1鏄ぇ鏈惀锛�0涓嶆槸澶ф湰钀�												*/
/* ************************************************************************ */
int IsBaseCamp(int i, int j)
{
	if (i * 5 + j == 1 || i * 5 + j == 3 || i * 5 + j == 56 || i * 5 + j == 58)
		return 1;
	else
		return 0;
}

/* ************************************************************************ */
/* 鍑芥暟鍔熻兘锛歩,j浣嶇疆鏄惁鏈夋瀛愬崰浣嶇殑琛岃惀										*/
/* 鎺ュ彛鍙傛暟锛�																*/
/*     char cMap[12][5] 妫嬬洏灞�闈�											*/
/*     int i,j 妫嬬洏浣嶇疆琛屽垪鍙�												*/
/* 杩斿洖鍊硷細																	*/
/*     1鏈夋瀛愬崰浣嶇殑琛岃惀,0涓嶆槸琛岃惀鎴栨槸绌鸿钀�								*/
/* ************************************************************************ */
int IsFilledCamp(char cMap[12][5], int i, int j)
{
	if (IsMoveCamp(i, j) && cMap[i][j] != '0')
		return 1;
	else
		return 0;
}
int Iszuoqian(int i, int j)
{
	if (i * 5 + j == 19 || i * 5 + j == 29 || i * 5 + j == 27 || i * 5 + j == 44 || i * 5 + j == 52 || i * 5 + j == 54)
		return 1;
	else
		return 0;
}

//(i锛宩)涓轰笉鍦ㄨ钀ヤ笖鍙互鍚戝彸鍓嶆柟绉诲姩鐨勬棗瀛�
//  1涓烘槸閭ｄ笁鐐癸紝0涓嶆槸閭ｄ笁鐐�
int Isyouqian(int i, int j)
{
	if (i * 5 + j == 15 || i * 5 + j == 25 || i * 5 + j == 27 || i * 5 + j == 40 || i * 5 + j == 50 || i * 5 + j == 52)
		return 1;
	else
		return 0;
}
//(i锛宩)涓轰笉鍦ㄨ钀ヤ笖鍙互鍚戝乏鍚庢柟绉诲姩鐨勬棗瀛�
//          1涓烘槸閭ｄ笁鐐癸紝0涓嶆槸閭ｄ笁鐐�

int Iszuohou(int i, int j)
{
	if (i * 5 + j == 7 || i * 5 + j == 9 || i * 5 + j == 19 || i * 5 + j == 32 || i * 5 + j == 34 || i * 5 + j == 44)
		return 1;
	else
		return 0;
}
//(i锛宩)涓轰笉鍦ㄨ钀ヤ笖鍙互鍚戝彸鍚庢柟绉诲姩鐨勬棗瀛�
//         1涓烘槸閭ｄ笁鐐癸紝0涓嶆槸閭ｄ笁鐐�
int Isyouhou(int i, int j)
{
	if (i * 5 + j == 5 || i * 5 + j == 7 || i * 5 + j == 15 || i * 5 + j == 30 || i * 5 + j == 32 || i * 5 + j == 40)
		return 1;
	else
		return 0;
}
/* ************************************************************************ */
/* 鍑芥暟鍔熻兘锛氬弻鏂瑰竷灞�鍚庢灞�鍒濆鍖�											*/
/* 鎺ュ彛鍙傛暟锛�																*/
/*     char cMap[12][5] 妫嬬洏灞�闈�											*/
/*     char *cOutMessage 甯冨眬瀛楃搴忓垪										*/
/* ************************************************************************ */
void InitMap(char cMap[12][5], char *cOutMessage)
{
	int i, j, k;
	for (i = 0; i<6; i++)	//鏍囪瀵规柟妫嬪瓙
		for (j = 0; j<5; j++)
			if (IsMoveCamp(i, j))
				cMap[i][j] = '0';
			else
				cMap[i][j] = 'X';
	k = 6;
	for (i = 6; i<12; i++)	//鏍囪宸辨柟妫嬪瓙
		for (j = 0; j<5; j++)
			if (IsMoveCamp(i, j))
				cMap[i][j] = '0';
			else
				cMap[i][j] = cOutMessage[k++];

}

//璁＄畻鎴戞柟妫嬪瓙杩樺墿澶氬皯涓�
//鍙傛暟 cMap 褰撳墠鍦板浘
//杩斿洖鍊间负鎴戞柟鍓╀綑妫嬪瓙
int NumChess(char cMap[12][5])
{
	int n = 0; //鎴戞柟妫嬪瓙鏁�
	int i, j;

	for (i = 0; i < 12; i++)
		for (j = 0; j < 5; j++)
			if (cMap[i][j] >= 'a'&&cMap[i][j] <= 'l')
				n++;
	return n;
}

//璁＄畻鏁屾柟妫嬪瓙杩樺墿澶氬皯涓�
//鍙傛暟 cMap 褰撳墠鍦板浘
//杩斿洖鍊间负鏁屾柟鍓╀綑妫嬪瓙
int NumOppChess(char cMap[12][5])
{
	int n = 0; //鎴戞晫妫嬪瓙鏁�
	int i, j;

	for (i = 0; i < 12; i++)
		for (j = 0; j < 5; j++)
			if (cMap[i][j] >= 'A'&&cMap[i][j] <= 'X')
				n++;
	return n;
}

void souhui(int n, int i, int sfen, int dz[25][14])         //sfen 鍥炴敹鐨勫垎鏁�   n涓烘棗瀛愪綅缃�   i涓烘棗瀛愬ぇ灏�
{
	int zong = 0;
	int n1;
	if (sfen == 0)
		return;
	if (i == 0 || i == 1 || i == 11)
		zong = 10000;
	else if (i>5 && i<10)
		zong = 30000;
	else
		zong = 20000;
	for (n1 = 0; n1<25; n1++)
	{
		if (n1 != n && (zong - dz[n][i]) != 0 && dz[n1][i]<9500)
			dz[n1][i] = 1.0*dz[n1][i] * (1 - 1.0*sfen / (zong - dz[n][i]));
	}
}

//鍒锋柊鐚滄祴姒傜巼琛�   //瀵规柟妫嬪瓙琚繁鏂瑰悆鎺�
void shuaxinG0(int m, char cMap[12][5], int dz[25][14], int i1, int j1, int i2, int j2)
{  //m=6
	int i, n, n1;
	int zong = 1, sfen = 0;
	if (i2 == 6 && j2 == 4)
		huang1 = 1;
	if (i1 != i2 && j1 != j2 && (IsRailway(i1, j1) && IsRailway(i2, j2)))    //鏁屾柟妫嬪瓙涓哄伐鍏�.......10    50     54     14
	{
		for (n = 0; n<25; n++)
		{
			if (dz[n][12] == i1 && dz[n][13] == j1)
			{
				dz[n][12] = 14;
				for (i = 0; i<12; i++)
				{
					if (dz[n][i] != 0 && i != 8 && dz[n][i] != 10000)
					{
						if (i == 0 || i == 1 || i == 11)
							zong = 10000;
						else if (i>5 && i<10)
							zong = 30000;
						else
							zong = 20000;
						for (n1 = 0; n1<25; n1++)
							if (n1 != n && dz[n1][i]<9000)
								dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));
						dz[n][i] = 0;
					}
				}
				souhui(n, 8, 10000 - dz[n][8], dz);
				dz[n][8] = 10000;		//宸ュ叺鍒嗗�煎彉10000
			}
		}
		return;
	}
	if (m<8 && m >= 0)//宸辨柟妫嬪瓙涓哄徃浠よ嚦鎺掗暱
	{
		for (n = 0; n<25; n++)
		{
			if (dz[n][12] == i1 && dz[n][13] == j1)
			{
				dz[n][12] = 14;
				for (i = 0; i<12; i++)
				{
					if (dz[n][i] != 0 && (i <= m || i>8) && dz[n][i] != 10000)    //涓嶆槸鎺掗暱鎴栬�呭伐鍏�
					{
						if (i == 0 || i == 1 || i == 11)
							zong = 10000;
						else if (i>5 && i<10)
							zong = 30000;
						else
							zong = 20000;
						for (n1 = 0; n1<25; n1++)
							if (n1 != n && dz[n1][i]<9000)
								dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));    //澧炲姞妫嬬洏涓婂叾浠栦綅缃瘮宸辨柟妫嬪瓙澶х殑鍒嗗�硷紝     琚悆鎺夌殑鏃楀瓙鍙兘涓烘帓闀垮拰宸ュ叺锛屾墍浠ュ叾浠栧湴鏂圭浉搴斿叾浠栧瓙鐨勫垎鍊煎鍔�
						dz[n][i] = 0;   			//鏁屾柟妫嬪瓙姝绘帀锛屾墍浠ユ浣嶇疆涓烘瘮宸辨柟妫嬪瓙澶х殑鍒嗗�间负0
					}
				}
				zong = 1;
				for (i = m + 1; i <= 8; i++)
					zong = zong + dz[n][i];
				for (i = m + 1; i <= 8; i++) //灏嗘鐩樹笂鍏朵粬鍦版柟姣旇妫嬪瓙灏忕殑鍒嗗�煎噺灏�
				{
					sfen = 1.0 * 10000 * dz[n][i] / zong - dz[n][i];
					souhui(n, i, sfen, dz);                                                        //杩欎釜浣嶇疆涓烘帓闀匡紝鐩稿簲鍏朵粬鍦版柟涓烘帓闀跨殑鐨勬鐜囧噺灏�
					dz[n][i] = 1.0 * 10000 * dz[n][i] / zong;
				}
			}
		}
	}
	if (m == 9)//宸辨柟妫嬪瓙涓哄湴闆�
	{
		for (n = 0; n<25; n++)
		{
			if (dz[n][12] == i1 && dz[n][13] == j1)
			{
				dz[n][12] = 14;
				for (i = 0; i<12; i++)
				{
					if (dz[n][i] != 0 && (i == 8 || i == 10) && dz[n][i] != 10000)    //涓嶆槸鐐稿脊鎴栬�呭伐鍏�
					{
						if (i == 0 || i == 1 || i == 11)
							zong = 10000;
						else if (i>5 && i<10)
							zong = 30000;
						else
							zong = 20000;
						for (n1 = 0; n1<25; n1++)
							if (n1 != n && dz[n1][i]<9000)
								dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));
						dz[n][i] = 0;
					}
				}
				zong = 1;
				for (i = 0; i<8; i++)
					zong = zong + dz[n][i];
				for (i = 0; i<8; i++) //灏嗘鐩樹笂鍏朵粬鍦版柟涓哄徃浠よ嚦鎺掗暱鐨勫垎鍊煎鍔�
				{
					sfen = 1.0 * 10000 * dz[n][i] / zong - dz[n][i];
					souhui(n, i, sfen, dz);
					dz[n][i] = 1.0 * 10000 * dz[n][i] / zong;
				}
			}
		}
	}
}
//瀵规柟鍚冩帀宸辨柟妫嬪瓙
void shuaxinG1(int m, char cMap[12][5], int dz[25][14], int i1, int j1, int i2, int j2)
{  //m=4 tuanzhang
	int i, n, n1;
	int zong = 1, sfen = 0;
	if (cMap[i2][j2] <= 'd')
	{
		for (n = 0; n < 25; n++)
			if (dz[n][12] == i1 && dz[n][13] == j1)
			{
				track[tra] = n;
				tra++;
			}
	}
	if ((i1 != i2 && j1 != j2 && IsRailway(i1, j1) && IsRailway(i2, j2)) || (m == 9))//鏁屾柟妫嬪瓙涓哄伐鍏�.......10    50     54     14
	{
		for (n = 0; n<25; n++)
		{
			if (dz[n][12] == i1 && dz[n][13] == j1)
			{
				dz[n][12] = i2;
				dz[n][13] = j2;
				for (i = 0; i<12; i++)
				{
					if (dz[n][i] != 0 && i != 8 && dz[n][i] != 10000)
					{
						if (i == 0 || i == 1 || i == 11)
							zong = 10000;
						else if (i>5 && i<10)
							zong = 30000;
						else
							zong = 20000;
						for (n1 = 0; n1<25; n1++)
							if (n1 != n && dz[n1][i]<9000)
								dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));
						dz[n][i] = 0;
					}
				}
				souhui(n, 8, 10000 - dz[n][8], dz);
				dz[n][8] = 10000;
			}
		}
		return;
	}
	if (m<9 && m >= 0)//宸辨柟妫嬪瓙涓哄啗闀胯嚦宸ュ叺		m>0
	{
		for (n = 0; n<25; n++)
		{
			if (dz[n][12] == i1 && dz[n][13] == j1)
			{
				dz[n][12] = i2;
				dz[n][13] = j2;

				for (i = 0; i<12; i++)
				{
					if (dz[n][i] != 0 && ((i >= m && i<9) || (i == 10)) && dz[n][i] != 10000)
					{
						if (i == 0 || i == 1 || i == 11)
							zong = 10000;
						else if (i>5 && i<10)
							zong = 30000;
						else
							zong = 20000;
						for (n1 = 0; n1<25; n1++)
							if (n1 != n && dz[n1][i]<9000)
								dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));    //澧炲姞妫嬬洏涓婂叾浠栦綅缃瘮宸辨柟妫嬪瓙灏忕殑鍒嗗�硷紝
						dz[n][i] = 0;            //宸辨柟妫嬪瓙姝绘帀锛屾墍浠ユ浣嶇疆涓烘瘮宸辨柟妫嬪瓙灏忕殑鍒嗗�间负0
					}
				}
				zong = 1;
				for (i = 0; i<m; i++)
					zong = zong + dz[n][i];
				for (i = 0; i<m; i++) //灏嗘鐩樹笂鍏朵粬鍦版柟姣旇妫嬪瓙澶х殑鍒嗗�煎噺灏�
				{
					sfen = 1.0 * 10000 * dz[n][i] / zong - dz[n][i];
					souhui(n, i, sfen, dz);
					dz[n][i] = 1.0 * 10000 * dz[n][i] / zong;
				}
			}
		}
	}
}
//鏁屾柟妫嬪瓙涓庡繁鏂规瀛愬姝�
void shuaxinG2(int m, char cMap[12][5], int dz[25][14], int i1, int j1, int i2, int j2)
{
	int i, n, n1;
	int zong = 0, sfen = 0;
	if (i1 != i2 && j1 != j2 && IsRailway(i1, j1) && IsRailway(i2, j2))//鏁屾柟妫嬪瓙涓哄伐鍏�.......10    50     54     14
	{

		for (n = 0; n<25; n++)
		{
			if (dz[n][12] == i1 && dz[n][13] == j1)
			{
				dz[n][12] = 14;
				for (i = 0; i<12; i++)
				{
					if (dz[n][i] != 0 && i != 8 && dz[n][i] != 10000)
					{
						if (i == 0 || i == 1 || i == 11)
							zong = 10000;
						else if (i>5 && i<10)
							zong = 30000;
						else
							zong = 20000;
						for (n1 = 0; n1<25; n1++)
							if (n1 != n && dz[n1][i]<9000)
								dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));
						dz[n][i] = 0;
					}
				}
				souhui(n, 8, 10000 - dz[n][8], dz);
				dz[n][8] = 10000;
			}
		}
		return;
	}
	if (m<9 && m >= 0)//宸辨柟妫嬪瓙涓哄徃浠よ嚦宸ュ叺
	{
		for (n = 0; n<25; n++)
		{
			if (dz[n][12] == i1 && dz[n][13] == j1)
			{
				dz[n][12] = 14;
				if (m == 0)  //宸辨柟妫嬪瓙涓哄徃浠�
				{
					if (jq == 1)//瀵规柟妫嬪瓙涓哄徃浠�
					{
						for (i = 0; i<12; i++)
						{
							if (dz[n][i] != 0 && i != 0 && dz[n][i] != 10000)
							{
								if (i == 0 || i == 1 || i == 11)
									zong = 10000;
								else if (i>5 && i<10)
									zong = 30000;
								else
									zong = 20000;
								for (n1 = 0; n1<25; n1++)
									if (n1 != n && dz[n1][i]<9500)
										dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));
								dz[n][i] = 0;
							}
						}
						dz[n][0] = 10000;
					}
					else      //瀵规柟妫嬪瓙涓虹偢寮�
					{
						for (i = 0; i<12; i++)
						{
							if (dz[n][i] != 0 && i != 10 && dz[n][i] != 10000)
							{
								if (i == 0 || i == 1 || i == 11)
									zong = 10000;
								else if (i>5 && i<10)
									zong = 30000;
								else
									zong = 20000;
								for (n1 = 0; n1<25; n1++)
									if (n1 != n && dz[n1][i]<9500)
										dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));
								dz[n][i] = 0;
							}
						}
						sfen = 10000 - dz[n][10];
						souhui(n, 10, sfen, dz);
						dz[n][10] = 10000;
					}
				}
				else   //宸辨柟妫嬪瓙涓哄啗闀垮埌宸ュ叺
				{
					if (m<2)
					{
						for (i = 0; i<12; i++)
						{
							if (dz[n][i] != 0 && (i != m && i != 10) && dz[n][i] != 10000)
							{
								if (i == 0 || i == 1 || i == 11)
									zong = 10000;
								else if (i>5 && i<10)
									zong = 30000;
								else
									zong = 20000;
								for (n1 = 0; n1<25; n1++)
									if (n1 != n && dz[n1][i]<9000)
										dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));
								dz[n][i] = 0;
							}
						}
						zong = dz[n][m] + dz[n][10] + 1;

						sfen = 1.0 * 10000 * dz[n][10] / zong - dz[n][10];
						souhui(n, 10, sfen, dz);
						dz[n][10] = 10000 * (1.0*dz[n][10] / zong);

						sfen = 1.0 * 10000 * dz[n][m] / zong - dz[n][m];
						souhui(n, m, sfen, dz);
						dz[n][m] = 10000 * (1.0*dz[n][m] / zong);
					}
					else
					{
						for (i = 0; i<12; i++)
						{
							if (dz[n][i] != 0 && i != m && dz[n][i] != 10000)
							{
								if (i == 0 || i == 1 || i == 11)
									zong = 10000;
								else if (i>5 && i<10)
									zong = 30000;
								else
									zong = 20000;
								for (n1 = 0; n1<25; n1++)
									if (n1 != n && dz[n1][i]<9000)
										dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));
								dz[n][i] = 0;
							}
						}

						sfen = 10000 - dz[n][m];
						souhui(n, m, sfen, dz);
						dz[n][m] = 10000;
					}

				}
			}
		}
	}
	if (m == 9)   //宸辨柟妫嬪瓙涓哄湴闆�
	{
		for (n = 0; n<25; n++)
		{
			if (dz[n][12] == i1 && dz[n][13] == j1)
			{
				dz[n][12] = 14;
				for (i = 0; i<12; i++)
				{
					if (dz[n][i] != 0 && i != 10 && dz[n][i] != 10000)
					{
						if (i == 0 || i == 1 || i == 11)
							zong = 10000;
						else if (i>5 && i<10)
							zong = 30000;
						else
							zong = 20000;
						for (n1 = 0; n1<25; n1++)
							if (n1 != n && dz[n1][i]<9000)
								dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));
						dz[n][i] = 0;
					}
				}
				sfen = 10000 - dz[n][10];
				souhui(n, 10, sfen, dz);
				dz[n][10] = 10000;
			}
		}
	}
	if (m == 10)
	{
		for (n = 0; n<25; n++)
		{
			if (dz[n][12] == i1 && dz[n][13] == j1)
			{
				dz[n][12] = 14;
			}
		}
	}
}
//鏁屾柟浠呯Щ鍔ㄦ瀛�
void shuaxinG3(int i1, int j1, int i2, int j2, int dz[25][14]) //浠呯Щ鍔ㄦ瀛�
{
	int n, n1, i;
	int sfen, zong = 0;
	if (i1 != i2 && j1 != j2 && IsRailway(i1, j1) && IsRailway(i2, j2))//鏁屾柟妫嬪瓙涓哄伐鍏�.......10    50     54     14
	{
		for (n = 0; n<25; n++)
		{
			if (dz[n][12] == i1 && dz[n][13] == j1)
			{
				dz[n][12] = i2;
				dz[n][13] = j2;
				for (i = 0; i<12; i++)
				{
					if (dz[n][i] != 0 && i != 8 && dz[n][i] != 10000)
					{
						if (i == 0 || i == 1 || i == 11)
							zong = 10000;
						else if (i>5 && i<10)
							zong = 30000;
						else
							zong = 20000;
						for (n1 = 0; n1<25; n1++)
							if (n1 != n && dz[n1][i]<9000)
								dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));
						dz[n][i] = 0;
					}
				}
				souhui(n, 8, 10000 - dz[n][8], dz);
				dz[n][8] = 10000;
			}
		}

	}
	for (n = 0; n<25; n++)
	{
		if (dz[n][12] == i1 && dz[n][13] == j1)
		{
			dz[n][12] = i2;
			dz[n][13] = j2;
			if (z1 == 1 && y21 == 2 && x21 == 1)
				dz[n][10] = 4000;
			if (z2 == 1 && y21 == 2 && x21 == 3)
				dz[n][10] = 4000;
			if (z3 == 1 && y21 == 4 && x21 == 1)
				dz[n][10] = 4000;
			if (z4 == 1 && y21 == 4 && x21 == 3)
				dz[n][10] = 4000;
		}
	}
}
//  //宸辨柟妫嬪瓙琚鏂瑰悆鎺�
void shuaxinR0(int m, char cMap[12][5], int dz[25][14], int i1, int j1, int i2, int j2)
{  //m=4 tuanzhang
	int i, n, n1;
	int zong = 1, sfen = 0;
	if (cMap[i1][j1] <= 'd')
	{
		for (n = 0; n < 25; n++)
			if (dz[n][12] == i2 && dz[n][13] == j2)
			{
				track[tra] = n;
				tra++;
			}
	}
	if (m == 8)//宸辨柟妫嬪瓙涓哄伐鍏�
	{
		for (n = 0; n<25; n++)
		{
			if (dz[n][12] == i2 && dz[n][13] == j2)
			{
				for (i = 0; i<12; i++)
				{
					if (dz[n][i] != 0 && (i == 8 || i == 9 || i == 10) && dz[n][i] != 10000)    //涓嶆槸,宸ュ叺,鐐稿脊锛屽湴闆�
					{
						if (i == 0 || i == 1 || i == 11)
							zong = 10000;
						else if (i>5 && i<10)
							zong = 30000;
						else
							zong = 20000;
						for (n1 = 0; n1<25; n1++)
							if (n1 != n && dz[n1][i]<9000)
								dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));    //澧炲姞妫嬬洏涓婂叾浠栦綅缃瘮宸辨柟妫嬪瓙灏忕殑鍒嗗�硷紝
						dz[n][i] = 0;            //宸辨柟妫嬪瓙姝绘帀锛屾墍浠ユ浣嶇疆鍦伴浄鐐稿脊鍒嗗�间负0
					}
				}
				zong = 1;    //   锛�  娌℃湁鍦伴浄锛�
				for (i = 0; i<m; i++)
					zong = zong + dz[n][i];
				for (i = 0; i<m; i++) //灏嗘鐩樹笂鍏朵粬鍦版柟姣旇妫嬪瓙澶х殑鍒嗗�煎噺灏�
				{
					sfen = 1.0 * 10000 * dz[n][i] / zong - dz[n][i];
					souhui(n, i, sfen, dz);
					dz[n][i] = 1.0 * 10000 * dz[n][i] / zong;
				}

			}
		}
	}
	if (m<8 && m>0)//宸辨柟妫嬪瓙涓哄啗闀胯嚦鎺掗暱
	{
		for (n = 0; n<25; n++)
		{
			if (dz[n][12] == i2 && dz[n][13] == j2)
			{
				for (i = 0; i<12; i++)
				{
					if (dz[n][i] != 0 && ((i >= m && i<9) || (i == 10)) && dz[n][i] != 10000)    //涓嶆槸鍥㈤暱鍒板伐鍏�
					{
						if (i == 0 || i == 1 || i == 11)
							zong = 10000;
						else if (i>5 && i<10)
							zong = 30000;
						else
							zong = 20000;
						for (n1 = 0; n1<25; n1++)
							if (n1 != n && dz[n1][i]<9000)
								dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));    //澧炲姞妫嬬洏涓婂叾浠栦綅缃瘮宸辨柟妫嬪瓙灏忕殑鍒嗗�硷紝
						dz[n][i] = 0;            //宸辨柟妫嬪瓙姝绘帀锛屾墍浠ユ浣嶇疆涓烘瘮宸辨柟妫嬪瓙灏忕殑鍒嗗�间负0(涓嶅彲鑳界殑妫嬪瓙)
					}
				}
				zong = 1;    //   锛�  娌℃湁鍦伴浄锛�
				for (i = 0; i<m; i++)
					zong = zong + dz[n][i];
				for (i = 0; i<m; i++) //灏嗘鐩樹笂鍏朵粬鍦版柟姣旇妫嬪瓙澶х殑鍒嗗�煎噺灏�
				{
					sfen = 1.0 * 10000 * dz[n][i] / zong - dz[n][i];
					souhui(n, i, sfen, dz);
					dz[n][i] = 1.0 * 10000 * dz[n][i] / zong;
				}

			}
		}
	}
	if (m == 0)// 宸辨柟妫嬪瓙涓哄徃浠わ紝鏁屾柟涓哄湴闆�
	{
		for (n = 0; n<25; n++)
		{
			if (dz[n][12] == i2 && dz[n][13] == j2)
			{
				souhui(n, 9, 10000 - dz[n][9], dz);
				dz[n][9] = 10000;
				for (i = 0; i<12; i++)
				{
					if (dz[n][i] != 0 && i != 9 && dz[n][i] != 10000)
					{
						if (i == 0 || i == 1 || i == 11)
							zong = 10000;
						else if (i>5 && i<10)
							zong = 30000;
						else
							zong = 20000;
						for (n1 = 0; n1<25; n1++)
							if (n1 != n && dz[n1][i]<9500)
								dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));
						dz[n][i] = 0;
					}
				}
			}
		}
	}
	if (i2 == 0 && j2 == 1)
	{
		dz[3][11] = 10000;
		dz[1][11] = 0;
		dz[3][7] = 0;  //鍙︿竴涓湴鏂逛负鍐涙棗锛屼负鎺掗暱鍜屽湴闆风殑鍒嗗�间负0
		dz[3][9] = 0;
		dz[1][7] = 6000;
		dz[1][9] = 4000;
	}
	if (i2 == 0 && j2 == 3)
	{
		dz[1][11] = 10000;
		dz[3][11] = 0;
		dz[1][7] = 0;
		dz[1][9] = 0;
		dz[3][7] = 6000;
		dz[3][9] = 4000;
	}
}
//宸辨柟鍚冩帀瀵规柟妫嬪瓙
void shuaxinR1(int m, char cMap[12][5], int dz[25][14], int i1, int j1, int i2, int j2)
{   //m=6
	int i, n, n1;
	int zong = 1, sfen = 0;
	if (m<8 && m >= 0)//宸辨柟妫嬪瓙涓哄徃浠よ嚦鎺掗暱
	{
		for (n = 0; n<25; n++)
		{
			if (dz[n][12] == i2 && dz[n][13] == j2)
			{
				dz[n][12] = 14;
				for (i = 0; i<12; i++)
				{
					if (dz[n][i] != 0 && (i <= m || i>8) && dz[n][i] != 10000)    //涓嶆槸鎺掗暱鎴栬�呭伐鍏�
					{
						if (i == 0 || i == 1 || i == 11)
							zong = 10000;
						else if (i>5 && i<10)
							zong = 30000;
						else
							zong = 20000;
						for (n1 = 0; n1<25; n1++)
							if (n1 != n && dz[n1][i]<9000)
								dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));    //澧炲姞妫嬬洏涓婂叾浠栦綅缃瘮宸辨柟妫嬪瓙澶х殑鍒嗗�硷紝     琚悆鎺夌殑鏃楀瓙鍙兘涓烘帓闀垮拰宸ュ叺锛屾墍浠ュ叾浠栧湴鏂圭浉搴斿叾浠栧瓙鐨勫垎鍊煎鍔�
						dz[n][i] = 0;            //鏁屾柟妫嬪瓙姝绘帀锛屾墍浠ユ浣嶇疆涓烘瘮宸辨柟妫嬪瓙澶х殑鍒嗗�间负0
					}
				}
				zong = 1;
				for (i = m + 1; i <= 8; i++)
					zong = zong + dz[n][i];
				for (i = m + 1; i <= 8; i++) //灏嗘鐩樹笂鍏朵粬鍦版柟姣旇妫嬪瓙灏忕殑鍒嗗�煎噺灏�
				{
					sfen = 1.0 * 10000 * dz[n][i] / zong - dz[n][i];
					souhui(n, i, sfen, dz);                                                        //杩欎釜浣嶇疆涓烘帓闀匡紝鐩稿簲鍏朵粬鍦版柟涓烘帓闀跨殑鐨勬鐜囧噺灏�
					dz[n][i] = 1.0 * 10000 * dz[n][i] / zong;
				}
			}
		}
	}
	if (m == 8)//宸辨柟涓哄伐鍏碉紝鏁屾柟涓哄湴闆�
	{
		for (n = 0; n<25; n++)
		{
			if (dz[n][12] == i2 && dz[n][13] == j2)
			{
				dz[n][12] = 14;
				souhui(n, 9, 10000 - dz[n][9], dz);
				dz[n][9] = 10000;
				for (i = 0; i<12; i++)
				{
					if (dz[n][i] != 0 && i != 9)
					{
						if (i == 0 || i == 1 || i == 11)
							zong = 10000;
						else if (i>5 && i<10)
							zong = 30000;
						else
							zong = 20000;
						for (n1 = 0; n1<25; n1++)
							if (n1 != n && dz[n1][i]<9000)
								dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));
						dz[n][i] = 0;
					}
				}
			}
		}

	}
	if (i2 == 0 && j2 == 1)
	{
		dz[3][11] = 10000;
		dz[1][11] = 0;
		dz[3][7] = 0;  //鍙︿竴涓湴鏂逛负鍐涙棗锛屼负鎺掗暱鍜屽湴闆风殑鍒嗗�间负0
		dz[3][9] = 0;
		dz[1][7] = 6000;
		dz[1][9] = 4000;
	}
	if (i2 == 0 && j2 == 3)
	{
		dz[1][11] = 10000;
		dz[3][11] = 0;
		dz[1][7] = 0;
		dz[1][9] = 0;
		dz[3][7] = 6000;
		dz[3][9] = 4000;
	}
}

//宸辨柟绉诲姩锛屽弻鏂规瀛愬姝�
void shuaxinR2(int m, char cMap[12][5], int dz[25][14], int i1, int j1, int i2, int j2)
{
	int i, n, n1;
	int zong = 1, sfen = 0;
	if (m<9 && m >= 0)//宸辨柟妫嬪瓙涓哄徃浠よ嚦宸ュ叺
	{
		for (n = 0; n<25; n++)
		{
			if (dz[n][12] == i2 && dz[n][13] == j2)
			{
				dz[n][12] = 14;
				if (m == 0)  //宸辨柟妫嬪瓙涓哄徃浠�
				{
					if (jq == 1)//瀵规柟妫嬪瓙涓哄徃浠�
					{
						for (i = 0; i<12; i++)
						{
							if (dz[n][i] != 0 && i != 0 && dz[n][i] != 10000)
							{
								if (i == 0 || i == 1 || i == 11)
									zong = 10000;
								else if (i>5 && i<10)
									zong = 30000;
								else
									zong = 20000;
								for (n1 = 0; n1<25; n1++)
									if (n1 != n && dz[n1][i]<9500)
										dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));
								dz[n][i] = 0;
							}
						}
						dz[n][0] = 10000;
					}
					else      //瀵规柟妫嬪瓙涓虹偢寮�
					{
						for (i = 0; i<12; i++)
						{
							if (dz[n][i] != 0 && i != 10 && dz[n][i] != 10000)
							{
								if (i == 0 || i == 1 || i == 11)
									zong = 10000;
								else if (i>5 && i<10)
									zong = 30000;
								else
									zong = 20000;
								for (n1 = 0; n1<25; n1++)
									if (n1 != n && dz[n1][i]<9500)
										dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));
								dz[n][i] = 0;
							}
						}
						sfen = 10000 - dz[n][10];
						souhui(n, 10, sfen, dz);
						dz[n][10] = 10000;
					}
				}
				else   //宸辨柟妫嬪瓙涓哄啗闀垮埌宸ュ叺
				{
					if (m<2)//濡傛灉宸辨柟妫嬪瓙涓哄笀闀夸互涓婏紝閭ｄ箞鏁屾柟妫嬪瓙鍙兘涓虹偢寮�
					{
						for (i = 0; i<12; i++)
						{
							if (dz[n][i] != 0 && i != m && i != 10 && dz[n][i] != 10000)
							{
								if (i == 0 || i == 1 || i == 11)
									zong = 10000;
								else if (i>5 && i<10)
									zong = 30000;
								else
									zong = 20000;
								for (n1 = 0; n1<25; n1++)
									if (n1 != n && dz[n1][i]<9000)
										dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));
								dz[n][i] = 0;
							}
						}

						zong = dz[n][m] + dz[n][10] + 1;  //闃叉鍒嗘瘝涓�0锛屽嚭閿欍��

						sfen = 1.0 * 10000 * dz[n][m] / zong - dz[n][m];
						souhui(n, m, sfen, dz);
						dz[n][m] = 1.0 * 10000 * dz[n][m] / zong;

						sfen = 1.0 * 10000 * dz[n][10] / zong - dz[n][10];
						souhui(n, 10, sfen, dz);
						dz[n][10] = 1.0 * 10000 * dz[n][10] / zong;
					}
					else//鏁屾柟妫嬪瓙涓哄笀闀夸互涓嬶紝鍒欎笉鑰冭檻鐐稿脊鐨勬鐜�
					{
						for (i = 0; i<12; i++)
						{
							if (dz[n][i] != 0 && i != m && i != 10 && dz[n][i] != 10000)
							{
								if (i == 0 || i == 1 || i == 11)
									zong = 10000;
								else if (i>5 && i<10)
									zong = 30000;
								else
									zong = 20000;
								for (n1 = 0; n1<25; n1++)
									if (n1 != n && dz[n1][i]<9000)
										dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (zong - dz[n][i]));
								dz[n][i] = 0;
							}
						}

						sfen = 10000 - dz[n][m];
						souhui(n, m, sfen, dz);
						dz[n][m] = 10000;
					}
				}
			}
		}
	}
	if (m == 10)
	{
		for (n = 0; n<25; n++)
		{
			if (dz[n][12] == i2 && dz[n][13] == j2)
			{
				dz[n][12] = 14;
			}
		}
	}
	if (i2 == 0 && j2 == 1)
	{
		dz[3][11] = 10000;
		dz[1][11] = 0;
		dz[3][7] = 0;  //鍙︿竴涓湴鏂逛负鍐涙棗锛屼负鎺掗暱鍜屽湴闆风殑鍒嗗�间负0
		dz[3][9] = 0;
		dz[1][7] = 6000;
		dz[1][9] = 4000;
	}
	if (i2 == 0 && j2 == 3)
	{
		dz[1][11] = 10000;
		dz[3][11] = 0;
		dz[1][7] = 0;
		dz[1][9] = 0;
		dz[3][7] = 6000;
		dz[3][9] = 4000;
	}
}

/* ************************************************************************ */
/* 鍑芥暟鍔熻兘锛氭牴鎹鍒ゅ弽棣堝埛鏂版鐩�											*/
/* 鎺ュ彛鍙傛暟锛�																*/
/*     char cMap[12][5] 妫嬬洏灞�闈�											*/
/*     char *cInMessage 鏉ヨ嚜瑁佸垽鐨凣O YXYX R YX鍛戒护							*/
/*     char *cOutMessage 鍙戠粰瑁佸垽鐨凚ESTMOVE YXYX鍛戒护						*/
/* ************************************************************************ */
void FreshMap(char cMap[12][5], char *cInMessage, char *cOutMessage, int dz[25][14])
{
	int x1, y1;				//璧风偣					//x1,y1,x2,y2,result鐢眂har鍨嬫敼涓篿nt鍨嬶紝娌′粈涔堝奖鍝�
	int x2, y2;				//钀界偣
	int result = -1, k;			//纰板瓙缁撴灉
	int n, i, n1, zong = 1;
	//鍒ゆ柇妯帓鏄惁灏变竴涓湴鏂规湁姒傜巼
	for (n = 0; n<25; n++)
	{
		k = 0;
		for (i = 0; i<12; i++)
		{
			if (dz[n][i] <= 50)
				k++;
		}
		if (k >= 11)
		{
			for (i = 0; i<12; i++)
			{
				if (dz[n][i]>50 && dz[n][i]<10000)
				{
					if (i == 0 || i == 1 || i == 11)
						zong = 10000;           //鍙镐护锛屽啗闀垮拰鍐涙棗閮藉彧鏈変竴涓�
					else if (i>5 && i<10)
						zong = 10000 * 3;         //姣忎釜妫嬪瓙鍏辨湁3涓�
					else
						zong = 10000 * 2;         //姣忎釜妫嬪瓙鏈変袱涓�
					for (n1 = 0; n1<25; n1++)
						if (n1 != n)
							dz[n1][i] = 1.0*dz[n1][i] * (1 - 1.0*(10000 - dz[n][i]) / (zong - dz[n][i]));    //纭畾鏌愪釜鍦版柟鏄粈涔堟棗瀛�
					souhui(n, i, 10000 - dz[n][i], dz);
					dz[n][i] = 10000;
				}

			}
		}

	}
	//鍒ゆ柇绔栨帓
	for (i = 0; i<12; i++)
	{
		k = 0;
		for (n = 0; n<25; n++)
			if (dz[n][i] >= 8000)
				k++;
		if (i == 0 || i == 1 || i == 11)
			zong = 1;
		else if (i>5 && i<10)
			zong = 3;
		else
			zong = 2;
		if (k == zong)            //纭畾妫嬪瓙鍦ㄤ粈涔堝湴鏂�(姣斿涓や釜鏃呴暱鐨勪綅缃兘鐭ラ亾浠ュ悗)
		{
			for (n = 0; n<25; n++)
			{
				if (dz[n][i]<8000)
				{
					for (k = 0; k<12; k++)
						if (k != i)
						{
							dz[n][k] = 1.0*dz[n][k] * (1 + 1.0*dz[n][i] / (10000 - dz[n][i]));      //绔栨帓姣忎釜涓嶆槸鏃呴暱鐨勪綅缃鍔犵浉搴旂殑鍒嗘暟
						}

					dz[n][i] = 0;        //灏嗕笉鏄�(鏃呴暱)鐨勪綅缃繘琛岃兘澶熸竻0
				}
			}
		}
	}

	if (cInMessage[0] == 'G')	// GO 鎸囦护
	{
		if (cInMessage[3] >= 'A' && cInMessage[3] <= 'L')																					//x,y鍧愭爣鍙戠敓瀵规崲锛屽洜涓轰笉涔犳儻
		{
			y1 = cInMessage[3] - 'A';
			x1 = cInMessage[4] - '0';
			y2 = cInMessage[5] - 'A';
			x2 = cInMessage[6] - '0';
			result = cInMessage[8] - '0';		//纰板瓙缁撴灉
			y11 = y1;
			x11 = x1;
			y21 = y2;
			x21 = x2;
			if (y21 == 2 && x21 == 1 && y11<5)
				z1++;
			if (y21 == 2 && x21 == 3 && y11<5)
				z2++;
			if (y21 == 4 && x21 == 1 && y11<5)
				z3++;
			if (y21 == 4 && x21 == 3 && y11<5)
				z4++;
			if (cInMessage[10] >= 'A' && cInMessage[10] <= 'L') //瀵规柟鍙镐护鎴樻鍚庢樉绀哄啗鏃椾綅缃�
			{
				cMap[(cInMessage[10] - 'A')][cInMessage[11] - '0'] = 'L';
				jq++;
				if (cInMessage[11] - '0' == 1)
				{
					dz[1][11] = 10000;
					dz[1][7] = 0;//姝ゅ湴涓哄啗鏃楋紝涓烘帓闀垮拰鍦伴浄鐨勫垎鍊间负0
					dz[1][9] = 0;
					dz[3][11] = 0;
					dz[3][7] = 6000;
					dz[3][9] = 4000;
				}
				if (cInMessage[11] - '0' == 3)
				{
					dz[3][11] = 10000;
					dz[1][11] = 0;
					dz[3][7] = 0;
					dz[3][9] = 0;
					dz[1][7] = 6000;
					dz[1][9] = 4000;
				}
			}
			/////鍒ゆ柇鍦伴浄鐨勬鐜�///////////
			if (y1<2)
			{
				for (n = 0; n<25; n++)
				{
					if (dz[n][12] == y1 && dz[n][13] == x1)
					{
						dz[n][12] = y2;
						dz[n][13] = x2;
						for (i = 0; i<12; i++)
						{
							if (dz[n][i] != 0 && i == 9 && dz[n][i] != 10000)
							{
								for (n1 = 0; n1<25; n1++)
								{
									if (n1 != n && dz[n1][i]<9000)
										dz[n1][i] = 1.0*dz[n1][i] * (1 + 1.0*dz[n][i] / (30000 - dz[n][i]));
								}
								dz[n][i] = 0;
							}
						}
						zong = 1;
						for (i = 0; i<9; i++)
							zong = zong + dz[n][i];
						for (i = 0; i<9; i++)
						{
							souhui(n, i, 1.0 * 10000 * dz[n][i] / (zong + 1) - dz[n][i], dz);
							dz[n][i] = 10000 * dz[n][i] / (zong + 1);
						}

					}
				}
			}
			switch (result)		//鏍规嵁涓嶅悓缁撴灉淇敼妫嬬洏
			{
			case 0:			//瀵规柟妫嬪瓙琚繁鏂瑰悆鎺�
				Ina_step[0] = 2;
				Ina_step[1] = 0;
				k = cMap[y2][x2] - 'a';  //缁堢偣涓哄繁鏂规瀛�
				shuaxinG0(k, cMap, dz, y1, x1, y2, x2);
				cMap[y1][x1] = '0';
				break;
			case 1:			//瀵规柟鍚冩帀宸辨柟妫嬪瓙
				Ina_step[0] = 2;
				Ina_step[1] = 0;
				k = cMap[y2][x2] - 'a';//缁堢偣涓哄繁鏂规瀛�
				shuaxinG1(k, cMap, dz, y1, x1, y2, x2);
				cMap[y2][x2] = cMap[y1][x1];
				cMap[y1][x1] = '0';
				break;
			case 2:			//鍙屾柟妫嬪瓙瀵规
				Ina_step[0] = 2;
				Ina_step[1] = 0;
				k = cMap[y2][x2] - 'a';//缁堢偣涓哄繁鏂规瀛�
				shuaxinG2(k, cMap, dz, y1, x1, y2, x2);
				cMap[y1][x1] = '0';
				cMap[y2][x2] = '0';
				break;
			case 3:			//瀵规柟绉诲姩妫嬪瓙銆併�併��///杩� 琛岃惀鐐稿脊姒傜巼澧炲姞
				Ina_step[1]++;
				shuaxinG3(y1, x1, y2, x2, dz);
				cMap[y2][x2] = cMap[y1][x1];
				cMap[y1][x1] = '0';
				break;
			}
			FILE *fp;
			fp = fopen("1", "a");
			fprintf(fp, "\n%d,%c,%c,%d,%d,%d,%d,%d\n", result, cMap[y2][x2], cMap[y1][x1], y2, x2, y1, x1, k);
			fclose(fp);
		}
	}
	if (cInMessage[0] == 'R')	// RESULT 鎸囦护
	{
		y1 = cOutMessage[9] - 'A';
		x1 = cOutMessage[10] - '0';
		y2 = cOutMessage[11] - 'A';
		x2 = cOutMessage[12] - '0';
		result = cInMessage[7] - '0';		//缁撴灉缁撴灉
		if (cInMessage[8] == ' ' && cInMessage[9] >= 'A' && cInMessage[9] <= 'L') //瀵规柟鍙镐护鎴樻鍚庢樉绀哄啗鏃椾綅缃�
		{
			cMap[(cInMessage[10] - 'A')][cInMessage[11] - '0'] = 'L';
			jq++;
			if (cInMessage[11] - '0' == 1)
			{
				dz[1][11] = 10000;
				dz[3][11] = 0;
				dz[1][7] = 0;//姝ゅ湴涓哄啗鏃楋紝涓烘帓闀垮拰鍦伴浄鐨勫垎鍊间负0
				dz[1][9] = 0;
			}
			if (cInMessage[11] - '0' == 3)
			{
				dz[3][11] = 10000;
				dz[1][11] = 0;
				dz[3][7] = 0;
				dz[3][9] = 0;
			}
		}
		switch (result)		//鏍规嵁涓嶅悓缁撴灉淇敼妫嬬洏
		{
		case 0:			//宸辨柟妫嬪瓙琚鏂瑰悆鎺�
			Ina_step[0] = 1;
			Ina_step[1] = 0;
			k = cMap[y1][x1] - 'a';  //璧风偣涓哄繁鏂规瀛�
			shuaxinR0(k, cMap, dz, y1, x1, y2, x2);//鏍规嵁宸辨柟鐨勬瀛愬埛鏂扮寽娴嬫鐜囪〃
			cMap[y1][x1] = '0';
			break;
		case 1:			//宸辨柟鍚冩帀瀵规柟妫嬪瓙
			Ina_step[0] = 1;
			Ina_step[1] = 0;
			k = cMap[y1][x1] - 'a';
			shuaxinR1(k, cMap, dz, y1, x1, y2, x2);
			cMap[y2][x2] = cMap[y1][x1];
			cMap[y1][x1] = '0';
			break;
		case 2:			//鍙屾柟妫嬪瓙瀵规
			Ina_step[0] = 1;
			Ina_step[1] = 0;
			k = cMap[y1][x1] - 'a';
			shuaxinR2(k, cMap, dz, y1, x1, y2, x2);
			cMap[y1][x1] = '0';
			cMap[y2][x2] = '0';
			break;
		case 3:			//宸辨柟绉诲姩妫嬪瓙
			Ina_step[1]++;
			cMap[y2][x2] = cMap[y1][x1];
			cMap[y1][x1] = '0';
			break;
		}
	}
	FILE *fp;
	fp = fopen("1", "a");
	fprintf(fp, "\n\n\n\n\n\n\n\n绗�%d姝ョ殑寮�濮�:\n", qqqqqq + 1);
	for (int i = 0; i != 12; i++)
	{
		for (int j = 0; j != 5; j++)
		{
			if (cMap[i][j] == 'X')
				fprintf(fp, "xx ");
			if (cMap[i][j] == 'L')
				fprintf(fp, "鏃� ");
			if (cMap[i][j] == '0')
				fprintf(fp, "   ");
			if (cMap[i][j] == 'a')
				fprintf(fp, "鍙� ");
			if (cMap[i][j] == 'b')
				fprintf(fp, "鍐� ");
			if (cMap[i][j] == 'c')
				fprintf(fp, "甯� ");
			if (cMap[i][j] == 'd')
				fprintf(fp, "鏃� ");
			if (cMap[i][j] == 'e')
				fprintf(fp, "鍥� ");
			if (cMap[i][j] == 'f')
				fprintf(fp, "钀� ");
			if (cMap[i][j] == 'g')
				fprintf(fp, "杩� ");
			if (cMap[i][j] == 'h')
				fprintf(fp, "鎺� ");
			if (cMap[i][j] == 'i')
				fprintf(fp, "鍏� ");
			if (cMap[i][j] == 'j')
				fprintf(fp, "闆� ");
			if (cMap[i][j] == 'k')
				fprintf(fp, "鐐� ");
			if (cMap[i][j] == 'l')
				fprintf(fp, "鏃� ");
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}
/* ************************************************************************ */
/* 鍑芥暟鍔熻兘锛氭牴鎹甀NFO鎸囦护,杩斿洖鍙傝禌闃熷悕										*/
/* 鎺ュ彛鍙傛暟锛�																*/
/*     char *cInMessage 鎺ユ敹鐨処NFO ver鎸囦护									*/
/*     char *cOutMessage 鍙傝禌闃熷悕											*/
/* ************************************************************************ */
void CulInfo(char *cInMessage, char *cVer, char *cOutMessage)
{
	strcpy(cVer, cInMessage + 5);																												//姝よ鍙ユ病鐢�
	strcpy(cOutMessage, "NAME ShenYang Aerospace University!");
}

/* ************************************************************************ */
/* 鍑芥暟鍔熻兘锛氭牴鎹甋TART鎸囦护,杩斿洖甯冨眬											*/
/* 鎺ュ彛鍙傛暟锛�																*/
/*     char *cInMessage 鎺ユ敹鐨凷TART first time steps鎸囦护					*/
/*     int *iFirst 鍏堣鏉僛0鍏堣锛�1鍚庤]										*/
/*     int *iTime 琛屾鏃堕棿闄愬埗(鍗曚綅绉�)[1000,3600]							*/
/*     int *iStep 杩涙敾绛夊緟闄愬埗(鍗曚綅姝�)[10,31]								*/
/*     char *cOutMessage 甯冨眬瀛楃搴忓垪										*/
/* ************************************************************************ */
void CulArray(char *cInMessage, int *iFirst, int *iTime, int *iStep, char *cOutMessage)
{
	*iFirst = cInMessage[6] - '0';
	*iTime = cInMessage[8] - '0';
	*iTime = *iTime * 10 + (cInMessage[9] - '0');
	*iTime = *iTime * 10 + (cInMessage[10] - '0');
	*iTime = *iTime * 10 + (cInMessage[11] - '0');
	*iStep = cInMessage[13] - '0';
	*iStep = *iStep * 10 + (cInMessage[14] - '0');
	if (*iFirst == 0)	//鍏堟墜		a鍙镐护,b鍐涢暱,c甯堥暱,d鏃呴暱,e鍥㈤暱,f钀ラ暱,g杩為暱,h鎺掗暱,i宸ュ叺,j鍦伴浄k鐐稿脊,l鍐涙棗   cdgdckhkfiifebejagjihljhg    hegickfkcibefigjajdhdljhg
						//	strcpy(cOutMessage,"ARRAY hcgcgkikgfdfdabejiiejljhh");         chdfckgkdiefabgjjiiejlghh           cdgdckhkfiifebejagjihljhg   cdedckfkfiiegbijajjghlhhg    cdedckfkfiiegbijajjghlhhg
		strcpy(cOutMessage, "ARRAY cehiakbcdikegfgjjdifhhglj");       //1.    cgdgckfkeiiefgbjajjdhlhhi   2.cgdgckekfiifeibjajjdhlhhg

	else			//鍚庢墜				chefckgkfiidgbjjidjeghhlj     hegickfkcibefigjajdhdljhg
	{
		//	strcpy(cOutMessage,"ARRAY hcgcgkikgfdfadbejiiejljhh");		chdfckgkdiefabijjgiejlghh    chdfckgkdiefabgjjiiejlghh   cdgdhkbkfiifecejagjihljhg
		strcpy(cOutMessage, "ARRAY cehiakbcdikegfgjjdifhhglj");       //1.       cgdgckfkeiiefgbjajjdhlhhi   2.cgdgckekfiifeibjajjdhlhhg
		Ina_step[0] = 1;
	}
}
//鎵�瑕佽璧扮殑浣嶇疆瀵瑰繁鏂归�犳垚鐨勫▉鑳佸垎鍊�
int weixie(int x, int y, int x1, int y1, int dz[25][14], char cMap[12][5])
{
	int n, score = 0, k, i, j, t, t1 = 0;
	if (cMap[x1][y1] == '0')
		return 0;
	for (n = 0; n<25; n++)//鍦ㄧ寽娴嬫鐜囪〃涓壘鍒版兂瑕佽璧扮殑浣嶇疆
	{
		if (dz[n][12] == x1 && dz[n][13] == y1)
			break;
	}
	k = cMap[x][y] - 'a';
	//杩涜鍒嗗�艰瘎浼�
	if (k >= 0 && k != 10)  //     k==10           涓虹偢寮癸紝鍏堜笉鑰冭檻
	{
		for (i = 0; i<9; i++)//鍙互琛岃蛋鐨勬鐨勫垎鍊�
		{
			if (i<k)
				score = score - dz[n][i];
			else if (i>k)
				score = score + dz[n][i];
			else
				continue;
		}
		if (cMap[x][y] == 'i')
			score = score + dz[n][9];
		else
			score = score - dz[n][9];//鍦伴浄鐨勫垎鍊�
	}
	//缁熻璇ユ瀛愭槸鍚︿负鐜版湁妫嬪瓙涓渶澶х殑涓や釜
	for (i = 0; i<12; i++)
	{
		for (j = 0; j<5; j++)
		{
			if (cMap[i][j] >= 'a' && cMap[i][j] <= 'i')
			{
				if (i == x && j == y)
					continue;
				else
				{
					t = cMap[i][j] - 'a';
					if (t <= k)   //姣旇緝涓や釜妫嬪瓙鐨勫ぇ灏�
						t1++;  //璁℃暟
				}
			}
		}
	}
	if (t1<3)//濡傛灉妫嬪瓙鏄繁鏂规渶澶х殑涓や釜鍑忓幓鐐稿脊鐨勫垎鍊�
		score = score - dz[n][10];
	return score;
}
int jweixie(int i, int j, int dz[25][14], char cMap[12][5])
{
	int i1, j1;
	int score = 0, score1 = 0;
	if (IsMoveCamp(i, j) == 1)
		score = 0;
	else//鍒嗘暟鍙栨渶灏忓�硷紝鍥犱负琛屾鍒嗘暟涓鸿璧版渶澶у垎鏁�
	{
		//鍚戝墠鎼滅储鎵惧埌瀵瑰繁鏂规瀛愮殑濞佽儊姒傜巼
		//涓嶅湪绗竴鎺掞紝涓嶅湪灞辩晫鍚庯紝鍓嶆柟涓嶆槸宸辨柟妫嬪瓙
		if (i>0 && !IsAfterHill(i, j) && !IsMyChess(cMap, i - 1, j))
		{
			score1 = weixie(i, j, i - 1, j, dz, cMap);
			if (score1<score)
				score = score1;
			if (i>1 && i<11 && (j == 0 || j == 4))//鍦ㄩ搧杞ㄤ笂
			{
				for (i1 = i - 1; i1>0; i1--)
				{
					if (cMap[i1][j] == '0')
						continue;
					else if (cMap[i1][j] >= 'A' && cMap[i1][j] <= 'X')
					{
						score1 = weixie(i, j, i1, j, dz, cMap);
						if (score1<score)
							score = score1;
						break;
					}
					else
						break;
				}
			}
		}
		//鍚戝悗鎼滅储
		if (i<11 && !IsBehindHill(i, j) && !IsMyChess(cMap, i + 1, j))
		{
			score1 = weixie(i, j, i + 1, j, dz, cMap);
			if (score1<score)
				score = score1;
			if (i>0 && i<10 && (j == 0 || j == 4))
			{
				for (i1 = i + 1; i1<11; i1++)
				{
					if (cMap[i1][j] == '0')
						continue;
					else if (cMap[i1][j] >= 'A' && cMap[i1][j] <= 'X')
					{
						score1 = weixie(i, j, i1, j, dz, cMap);
						if (score1<score)
							score = score1;
						break;
					}
					else
						break;
				}
			}
		}
		//鍚戝乏鎼滅储
		if (j>0 && !IsMyChess(cMap, i, j - 1))
		{
			score1 = weixie(i, j, i, j - 1, dz, cMap);
			if (score1<score)
				score = score1;
			if (j>0 && j<5 && (i == 1 || i == 5 || i == 6 || i == 10))
			{
				for (j1 = j - 1; j1 >= 0; j1--)
				{
					if (cMap[i][j1] == '0')
						continue;
					else if (cMap[i][j1] >= 'A' && cMap[i][j1] <= 'X')
					{
						score1 = weixie(i, j, i, j1, dz, cMap);
						if (score1<score)
							score = score1;
						break;
					}
					else
						break;
				}
			}
		}
		//鍚戝彸鎼滅储
		if (j<4 && !IsMyChess(cMap, i, j + 1))
		{
			score1 = weixie(i, j, i, j + 1, dz, cMap);
			if (score1<score)
				score = score1;
			if (j >= 0 && j<4 && (i == 1 || i == 5 || i == 6 || i == 10))
			{
				for (j1 = j + 1; j1<5; j1++)
				{
					if (cMap[i][j1] == '0')
						continue;
					else if (cMap[i][j1] >= 'A' && cMap[i][j1] <= 'X')
					{
						score1 = weixie(i, j, i, j1, dz, cMap);
						if (score1<score)
							score = score1;
						break;
					}
					else
						break;
				}
			}
		}
	}
	return score;
}
int Oppnextmove(int i, int j, char cMap[12][5], int allmove[200][2])
{
	int k = 0, i1, j1, num = 0, num1, iSaMove[40][2];
	char cmap[12][5];
	if (IsOppChess(cMap, i, j) && !IsBaseCamp(i, j))
	{
		//鍙互鍓嶇Щ:涓嶅湪绗竴琛�,涓嶅湪灞辩晫鍚�,鍓嶆柟涓嶆槸宸辨柟妫嬪瓙,鍓嶆柟涓嶆槸鏈夋瀛愬崰棰嗙殑琛岃惀
		if (i>0 && !IsAfterHill(i, j) && !IsOppChess(cMap, i - 1, j) && !IsFilledCamp(cMap, i - 1, j))
		{
			allmove[k][0] = i - 1;
			allmove[k][1] = j;
			k++;
			if ((j == 0 || j == 4) && i>0 && i<11)
			{
				for (i1 = i - 1; i1>0; i1--)
				{
					if (cMap[i1][j] == '0')
					{
						allmove[k][0] = i1;
						allmove[k][1] = j;
						k++;
					}
					else if (cMap[i1][j] >= 'a' && cMap[i1][j] <= 'l')
					{
						allmove[k][0] = i1;
						allmove[k][1] = j;
						k++;
						break;
					}
					else break;
				}
			}
		}
		//鍙互宸︾Щ:涓嶅湪鏈�宸﹀垪,宸︿晶涓嶆槸宸辨柟妫嬪瓙,宸︿晶涓嶆槸琚崰鐢ㄧ殑琛岃惀
		if (j>0 && !IsOppChess(cMap, i, j - 1) && !IsFilledCamp(cMap, i, j - 1))
		{
			allmove[k][0] = i;
			allmove[k][1] = j - 1;
			k++;
			//鏄惁鍦�1,5,6,10閾侀亾涓�
			if (i == 1 || i == 5 || i == 6 || i == 10)
			{
				for (int i1 = j - 1; i1 >= 0; i1--)
				{
					if (cMap[i][i1] == '0')
					{
						allmove[k][0] = i;
						allmove[k][1] = i1;
						k++;
					}
					else if (cMap[i][i1] >= 'a'&&cMap[i][i1] <= 'l')
					{
						allmove[k][0] = i;
						allmove[k][1] = i1;
						k++;
						break;
					}
					else break;
				}
			}
		}
		//鍙互鍙崇Щ:涓嶅湪鏈�鍙冲垪,鍙充晶涓嶆槸宸辨柟妫嬪瓙,鍙充晶涓嶆槸琚崰鐢ㄧ殑琛岃惀
		if (j<4 && !IsOppChess(cMap, i, j + 1) && !IsFilledCamp(cMap, i, j + 1))
		{
			allmove[k][0] = i;
			allmove[k][1] = j + 1;
			k++;
			//鏄惁鍦�1,5,6,10閾侀亾涓�
			if (i == 1 || i == 5 || i == 6 || i == 10)
			{
				for (int i1 = j + 1; i1<5; i1++)
				{
					if (cMap[i][i1] == '0')
					{
						allmove[k][0] = i;
						allmove[k][1] = i1;
						k++;
					}
					else if (cMap[i][i1] >= 'a'&&cMap[i][i1] <= 'l')
					{
						allmove[k][0] = i;
						allmove[k][1] = i1;
						k++;
						break;
					}
					else break;
				}
			}
		}

		//鍙互鍚庣Щ锛氫笉鍦ㄦ渶鍚庝竴鍒楋紝鍚庢柟涓嶆槸宸辨柟鏃楀瓙锛屽悗闈笉鏄凡鍗犳湁鐨勮钀�
		if (i<11 && !IsBehindHill(i, j) && !IsOppChess(cMap, i + 1, j) && !IsFilledCamp(cMap, i + 1, j))
		{
			allmove[k][0] = i + 1;
			allmove[k][1] = j;

			k++;
			//鍙互鍦ㄩ搧杞ㄤ袱渚у悜鍚庣Щ鍔紝鍚庢柟涓嶆槸宸辨柟鏃楀瓙锛屼笉鏄涓�琛岋紝涓嶅湪鏈�鍚庝竴琛�
			if ((j == 0 || j == 4) && i>0 && i<11)
			{
				for (i1 = i + 1; i1<11; i1++)
				{
					if (cMap[i1][j] == '0')
					{
						allmove[k][0] = i1;
						allmove[k][1] = j;

						k++;
					}
					else if (cMap[i1][j] >= 'a' && cMap[i1][j] <= 'l')
					{
						allmove[k][0] = i1;
						allmove[k][1] = j;
						k++;
						break;
					}
					else  break;
				}

			}
		}
		//鍙互宸﹀墠绉伙細宸﹀墠鏂逛笉鏄凡鍗犳湁鐨勮钀ワ紝涓嶆槸宸辨柟鏃楀瓙
		if ((Iszuoqian(i, j) || IsMoveCamp(i, j)) && !IsOppChess(cMap, i - 1, j - 1) && !IsFilledCamp(cMap, i - 1, j - 1))
		{
			allmove[k][0] = i - 1;
			allmove[k][1] = j - 1;

			k++;
		}
		//鍙互宸﹀悗绉伙細宸﹀悗鏂逛笉鏄繁鏂规棗瀛愶紝涓嶆槸宸插崰鏈夌殑琛岃惀
		if ((Iszuohou(i, j) || IsMoveCamp(i, j)) && !IsOppChess(cMap, i + 1, j - 1) && !IsFilledCamp(cMap, i + 1, j - 1))
		{
			allmove[k][0] = i + 1;
			allmove[k][1] = j - 1;

			k++;
		}
		//鍙互鍙冲墠绉伙細鍙冲墠鏂逛笉鏄繁鏂规棗瀛愶紝涓嶆槸宸插崰鏈夌殑琛岃惀
		if ((Isyouqian(i, j) || IsMoveCamp(i, j)) && !IsOppChess(cMap, i - 1, j + 1) && !IsFilledCamp(cMap, i - 1, j + 1))
		{
			allmove[k][0] = i - 1;
			allmove[k][1] = j + 1;

			k++;
		}
		//鍙互鍙冲悗绉伙細鍙冲悗鏂逛笉鏄繁鏂规棗瀛愶紝涓嶆槸宸插崰鏈夌殑琛岃惀
		if ((Isyouhou(i, j) || IsMoveCamp(i, j)) && !IsOppChess(cMap, i + 1, j + 1) && !IsFilledCamp(cMap, i + 1, j + 1))
		{
			allmove[k][0] = i + 1;
			allmove[k][1] = j + 1;
			k++;
		}
	}

	return k;
}
//宸辨柟鏌愪釜浣嶇疆鐨勬瀛愮殑涓嬩竴姝ヨ妫嬬殑鎵�鏈変綅缃�
int nextmove1(int i, int j, char cMap[12][5], int allmove[200][2])
{
	int k = 0, i1, j1, num = 0, num1, iSaMove[40][2];
	char cmap[12][5];
	if (IsMyMovingChess(cMap, i, j) && !IsBaseCamp(i, j))  //宸辨柟涓嶅湪澶ф湰钀ョ殑鍙Щ鍔ㄦ瀛�
	{
		//宸ュ叺褰㈡
		if (cMap[i][j] == 'i' && IsRailway(i, j))
		{
			iSaMove[0][0] = i;
			iSaMove[0][1] = j;
			for (i1 = 0; i1<12; i1++)
			{
				for (j1 = 0; j1<5; j1++)
					cmap[i1][j1] = cMap[i1][j1];
			}
			num = SapperRail(iSaMove, cmap, i, j, 0);
			for (num1 = 1; num1<num; num1++)
			{
				allmove[k][0] = iSaMove[num1][0];
				allmove[k][1] = iSaMove[num1][1];
				k++;
			}
		}
		//鍙互鍓嶇Щ:涓嶅湪绗竴琛�,涓嶅湪灞辩晫鍚�,鍓嶆柟涓嶆槸宸辨柟妫嬪瓙,鍓嶆柟涓嶆槸鏈夋瀛愬崰棰嗙殑琛岃惀
		if (i>0 && !IsAfterHill(i, j) && !IsMyChess(cMap, i - 1, j) && !IsFilledCamp(cMap, i - 1, j))
		{
			allmove[k][0] = i - 1;
			allmove[k][1] = j;
			k++;
			if ((j == 0 || j == 4) && i>0 && i<11)
			{
				for (i1 = i - 1; i1>0; i1--)
				{
					if (cMap[i1][j] == '0')
					{
						allmove[k][0] = i1;
						allmove[k][1] = j;
						k++;
					}
					else if (cMap[i1][j] >= 'A' && cMap[i1][j] == 'X')
					{
						allmove[k][0] = i1;
						allmove[k][1] = j;
						k++;
						break;
					}
					else break;
				}
			}
		}
		//鍙互宸︾Щ:涓嶅湪鏈�宸﹀垪,宸︿晶涓嶆槸宸辨柟妫嬪瓙,宸︿晶涓嶆槸琚崰鐢ㄧ殑琛岃惀
		if (j>0 && !IsMyChess(cMap, i, j - 1) && !IsFilledCamp(cMap, i, j - 1))
		{
			allmove[k][0] = i;
			allmove[k][1] = j - 1;
			k++;
			//鏄惁鍦�1,5,6,10閾侀亾涓�
			if (i == 1 || i == 5 || i == 6 || i == 10)
			{
				for (int i1 = j - 1; i1 >= 0; i1--)
				{
					if (cMap[i][i1] == '0')
					{
						allmove[k][0] = i;
						allmove[k][1] = i1;
						k++;
					}
					else if (cMap[i][i1] >= 'A'&&cMap[i][i1] <= 'X')
					{
						allmove[k][0] = i;
						allmove[k][1] = i1;
						k++;
						break;
					}
					else break;
				}
			}
		}
		//鍙互鍙崇Щ:涓嶅湪鏈�鍙冲垪,鍙充晶涓嶆槸宸辨柟妫嬪瓙,鍙充晶涓嶆槸琚崰鐢ㄧ殑琛岃惀
		if (j<4 && !IsMyChess(cMap, i, j + 1) && !IsFilledCamp(cMap, i, j + 1))
		{
			allmove[k][0] = i;
			allmove[k][1] = j + 1;
			k++;
			//鏄惁鍦�1,5,6,10閾侀亾涓�
			if (i == 1 || i == 5 || i == 6 || i == 10)
			{
				for (int i1 = j + 1; i1<5; i1++)
				{
					if (cMap[i][i1] == '0')
					{
						allmove[k][0] = i;
						allmove[k][1] = i1;
						k++;
					}
					else if (cMap[i][i1] >= 'A'&&cMap[i][i1] <= 'X')
					{
						allmove[k][0] = i;
						allmove[k][1] = i1;
						k++;
						break;
					}
					else break;
				}
			}
		}

		//鍙互鍚庣Щ锛氫笉鍦ㄦ渶鍚庝竴鍒楋紝鍚庢柟涓嶆槸宸辨柟鏃楀瓙锛屽悗闈笉鏄凡鍗犳湁鐨勮钀�
		if (i<11 && !IsBehindHill(i, j) && !IsMyChess(cMap, i + 1, j) && !IsFilledCamp(cMap, i + 1, j))
		{
			allmove[k][0] = i + 1;
			allmove[k][1] = j;

			k++;
			//鍙互鍦ㄩ搧杞ㄤ袱渚у悜鍚庣Щ鍔紝鍚庢柟涓嶆槸宸辨柟鏃楀瓙锛屼笉鏄涓�琛岋紝涓嶅湪鏈�鍚庝竴琛�
			if ((j == 0 || j == 4) && i>0 && i<11)
			{
				for (i1 = i + 1; i1<11; i1++)
				{
					if (cMap[i1][j] == '0')
					{
						allmove[k][0] = i1;
						allmove[k][1] = j;

						k++;
					}
					else if (cMap[i1][j] >= 'A' && cMap[i1][j] <= 'X')
					{
						allmove[k][0] = i1;
						allmove[k][1] = j;
						k++;
						break;
					}
					else  break;
				}

			}
		}
		//鍙互宸﹀墠绉伙細宸﹀墠鏂逛笉鏄凡鍗犳湁鐨勮钀ワ紝涓嶆槸宸辨柟鏃楀瓙
		if ((Iszuoqian(i, j) || IsMoveCamp(i, j)) && !IsMyChess(cMap, i - 1, j - 1) && !IsFilledCamp(cMap, i - 1, j - 1))
		{
			allmove[k][0] = i - 1;
			allmove[k][1] = j - 1;

			k++;
		}
		//鍙互宸﹀悗绉伙細宸﹀悗鏂逛笉鏄繁鏂规棗瀛愶紝涓嶆槸宸插崰鏈夌殑琛岃惀
		if ((Iszuohou(i, j) || IsMoveCamp(i, j)) && !IsMyChess(cMap, i + 1, j - 1) && !IsFilledCamp(cMap, i + 1, j - 1))
		{
			allmove[k][0] = i + 1;
			allmove[k][1] = j - 1;

			k++;
		}
		//鍙互鍙冲墠绉伙細鍙冲墠鏂逛笉鏄繁鏂规棗瀛愶紝涓嶆槸宸插崰鏈夌殑琛岃惀
		if ((Isyouqian(i, j) || IsMoveCamp(i, j)) && !IsMyChess(cMap, i - 1, j + 1) && !IsFilledCamp(cMap, i - 1, j + 1))
		{
			allmove[k][0] = i - 1;
			allmove[k][1] = j + 1;

			k++;
		}
		//鍙互鍙冲悗绉伙細鍙冲悗鏂逛笉鏄繁鏂规棗瀛愶紝涓嶆槸宸插崰鏈夌殑琛岃惀
		if ((Isyouhou(i, j) || IsMoveCamp(i, j)) && !IsMyChess(cMap, i + 1, j + 1) && !IsFilledCamp(cMap, i + 1, j + 1))
		{
			allmove[k][0] = i + 1;
			allmove[k][1] = j + 1;
			k++;
		}
	}
	return k;
}

void mychessdx(char cMap[12][5], char mc[25])   //灏嗘垜鏂规瀛愭寜鐓ф鍔涚殑澶у皬鎺掑簭
{												//鎵惧埌鎴戞柟妫嬪瓙闄や簡鍙镐护鏈�澶х殑涓や釜
	int i = 0, l;
	for (int i2 = 0; i2<12; i2++)  // 鎵惧繁鏂圭偢寮圭殑鏁扮洰
	{
		for (int j2 = 0; j2<5; j2++)
			if (cMap[i2][j2] >= 'a' && cMap[i2][j2] <= 'l')
			{
				mc[i] = cMap[i2][j2];
				i++;
				l = i;
			}
	}
	for (i = 0; i<l; i++)
	{
		for (int j = 0; j + i<l - 1; j++)
		{
			if (mc[j]>mc[j + 1])
			{
				char flag = mc[j];
				mc[j] = mc[j + 1];
				mc[j + 1] = flag;
			}
		}
	}
}

void jushipg(char cMap[12][5], int dz[25][14])
{
	if (cMap[11][1] == 'l')    ///宸辨柟鍐涙棗鐨勪綅缃�
	{
		qipanfen[6][0] = 130;
		qipanfen[7][0] = 120;
		qipanfen[7][1] = 600;
		qipanfen[8][0] = 120;
		qipanfen[8][1] = 80;
		qipanfen[9][0] = 120;
		qipanfen[9][1] = 700;
		qipanfen[10][0] = 600;
		qipanfen[10][1] = 200;
	}
	if (cMap[11][3] == 'l')
	{
		qipanfen[6][4] = 130;
		qipanfen[7][4] = 120;
		qipanfen[7][3] = 600;
		qipanfen[8][4] = 120;
		qipanfen[8][3] = 80;
		qipanfen[9][4] = 120;
		qipanfen[9][3] = 700;
		qipanfen[10][4] = 600;
		qipanfen[10][3] = 200;
	}
	if (dz[1][11] == 10000)  //鏁屾柟鍐涙棗鐨勪綅缃�
	{
		qipanfen[0][3] = -10000;
		qipanfen[0][4] = -10000;
		qipanfen[0][1] = 10000;
		qipanfen[0][0] = 600;
		qipanfen[1][0] = 400;
		qipanfen[1][1] = 700;
		qipanfen[2][0] = 300;
		qipanfen[2][1] = 900;
		qipanfen[3][0] = 240;
		qipanfen[3][1] = 100;
		qipanfen[4][0] = 230;
		qipanfen[4][1] = 500;
		qipanfen[5][0] = 220;
	}
	if (dz[3][11] == 10000)
	{
		qipanfen[0][1] = -10000;
		qipanfen[0][0] = -10000;
		qipanfen[0][3] = 10000;
		qipanfen[0][4] = 600;
		qipanfen[1][4] = 400;
		qipanfen[1][3] = 700;
		qipanfen[2][4] = 300;
		qipanfen[2][3] = 900;
		qipanfen[3][4] = 240;
		qipanfen[3][3] = 100;
		qipanfen[4][4] = 230;
		qipanfen[4][3] = 500;
		qipanfen[5][4] = 220;
	}
}
int walei1(char cMap[12][5], int dz[25][14])
{
	int k = 0;
	if (cMap[1][0] == '0' || (cMap[1][0] == 'X' && Judge(1, 0, 9, dz)>5000))
	{
		if (cMap[1][1] == '0' || (cMap[1][1] == 'X' && Judge(1, 1, 9, dz)>5000))
			k = 1;
		if (cMap[0][0] == '0' || (cMap[0][0] == 'X' && Judge(0, 0, 9, dz)>5000))
			k = 1;
	}
	return k;
}
int walei3(char cMap[12][5], int dz[25][14])
{
	int k = 0;
	if (cMap[1][4] == '0' || (cMap[1][4] == 'X' && Judge(1, 4, 9, dz)>5000))
	{
		if (cMap[1][3] == '0' || (cMap[1][3] == 'X' && Judge(1, 3, 9, dz)>5000))
			k = 1;
		if (cMap[0][4] == '0' || (cMap[0][4] == 'X' && Judge(0, 4, 9, dz)>5000))
			k = 1;
	}
	return k;
}
int walei(char cMap[12][5], int dz[25][14])//鍒ゆ柇鏁屾柟鍐涙棗闄勮繎鏄惁鏈夊湴闆�
{
	int k = 0;
	if (dz[1][11]>9000)
	{
		if (cMap[1][0] == '0' || (cMap[1][0] == 'X' && Judge(1, 0, 9, dz)>5000))
		{
			if (cMap[1][1] == '0' || (cMap[1][1] == 'X' && Judge(1, 1, 9, dz)>5000))
				k = 1;
			if (cMap[0][0] == '0' || (cMap[0][0] == 'X' && Judge(0, 0, 9, dz)>5000))
				k = 1;
		}
		if ((cMap[1][4] == '0' || (cMap[1][4] == 'X' && Judge(1, 4, 9, dz)>5000)) && (cMap[1][3] == '0' || (cMap[1][3] == 'X' && Judge(1, 3, 9, dz)>5000)) && (cMap[1][2] == '0' || (cMap[1][2] == 'X' && Judge(1, 2, 9, dz)>5000)) && (cMap[1][1] == '0' || (cMap[1][1] == 'X' && Judge(1, 1, 9, dz)>5000)))
			k = 1;
	}
	else if (dz[3][11]>9000)
	{
		if (cMap[1][4] == '0' || (cMap[1][4] == 'X' && Judge(1, 4, 9, dz)>5000))
		{
			if (cMap[1][4] == '0' || (cMap[1][4] == 'X' && Judge(1, 4, 9, dz)>5000))
				k = 1;
			if (cMap[0][4] == '0' || (cMap[0][4] == 'X' && Judge(0, 4, 9, dz)>5000))
				k = 1;
		}
		if ((cMap[1][0] == '0' || (cMap[1][0] == 'X' && Judge(1, 0, 9, dz)>5000)) && (cMap[1][1] == '0' || (cMap[1][1] == 'X' && Judge(1, 1, 9, dz)>5000)) && (cMap[1][2] == '0' || (cMap[1][2] == 'X' && Judge(1, 2, 9, dz)>5000)) && (cMap[1][3] == '0' || (cMap[1][3] == 'X' && Judge(1, 3, 9, dz)>5000)))
			k = 1;
	}
	else
	{
		if (walei1(cMap, dz) && walei3(cMap, dz))
			k = 1;
		if ((cMap[1][4] == '0' || (cMap[1][4] == 'X' && Judge(1, 4, 9, dz)>5000)) && (cMap[1][3] == '0' || (cMap[1][3] == 'X' && Judge(1, 3, 9, dz)>5000)) && (cMap[1][2] == '0' || (cMap[1][2] == 'X' && Judge(1, 2, 9, dz)>5000)) && (cMap[1][1] == '0' || (cMap[1][1] == 'X' && Judge(1, 1, 9, dz)>5000)))
			k = 1;
		if ((cMap[1][0] == '0' || (cMap[1][0] == 'X' && Judge(1, 0, 9, dz)>5000)) && (cMap[1][1] == '0' || (cMap[1][1] == 'X' && Judge(1, 1, 9, dz)>5000)) && (cMap[1][2] == '0' || (cMap[1][2] == 'X' && Judge(1, 2, 9, dz)>5000)) && (cMap[1][3] == '0' || (cMap[1][3] == 'X' && Judge(1, 3, 9, dz)>5000)))
			k = 1;
	}

	return k;
}
int DefendFlag(char cMap[12][5], int i0, int j0, int i1, int j1)
{
	int i = 10, j, Score = 10000000;
	char ChessRank[25];
	if (cMap[11][1] == 'l')
		j = 1;
	else
		j = 3;
	if ((IsOppChess(cMap, i, j)) && i == i1 && j == j1 || (IsOppChess(cMap, i, 2) && i1 == i && j1 == 2))
	{
		mychessdx(cMap, ChessRank);
		for (int k = 0; k < NumChess(cMap); k++)
			if (cMap[i0][j0] == ChessRank[k])
				return Score - k;
	}
	return 0;
}
int DefendLeft(int i0, int j0, int i1, int j1, char cMap[12][5])//鍫靛乏缈�
{
	int i = 6, j = 0, Score = 20000;
	char ChessRanking[25];
	if (cMap[i0][j0] == 'k')
		return 0;
	if (cMap[7][1] == 'k' || cMap[7][0] == 'k')
	{
		if (i0 == i && j0 == j)
			return -50000;
		if (cMap[i][j] == '0' && i1 == i && j1 == j)
		{
			mychessdx(cMap, ChessRanking);
			for (int k = 0; k < NumChess(cMap); k++)
				if (cMap[i0][j0] == ChessRanking[k])

					return Score - k;
		}
	}
	return 0;
}
int DefendRight(int i0, int j0, int i1, int j1, char cMap[12][5])//鍫靛彸缈�
{
	int i = 6, j = 4, Score = 50000;
	char ChessRanking[25];
	if (cMap[7][3] == 'k')
	{
		if (i0 == i && j0 == j)
			return -500000;
		if (cMap[i][j] == '0' && i1 == i && j1 == j)
		{
			mychessdx(cMap, ChessRanking);
			for (int k = 0; k < NumChess(cMap); k++)
				if (cMap[i0][j0] == ChessRanking[k])

					return Score - k;
		}
	}
	return 0;
}
int AttackFor31(char cMap[12][5], int i0, int j0, int i1, int j1)
{
	if (Ina_step[0] == 2 && Ina_step[1] > 15)
	{
		if (i0 == 7 && j0 == 0 && cMap[i0][j0] != 'k'&&i1 > 7 && j1 == 0)
			return 50000;
		if (IsMyChess(cMap, 6, 0))
			if (cMap[i0][j0] == 'k' && j1 == 0 && i1 == 7 && cMap[7][0] != 'X')
				return 50000;
		if (i0 == 6 && j0 == 0)
		{
			bool Flag = 0;
			for (int i = 8; i>6; i--)
				if (cMap[i][0] == 'k')
				{
					Flag = 1;
					break;
				}
			if (Flag)
			{
				if (IsOppChess(cMap, i1, j1) && j1 == 0)
					return 80000;
			}
		}
	}
	return 0;
}


int pinggu(int i, int j, int i1, int j1, int dz[25][14], char cMap[12][5])
{
	int zha = 0;
	char mchess[25];
	int score = 0, weixief = 0, qipan = 0, jweixief = 0, sanyif = 0, teshu = 0, score1 = 0;
	bool sanyi1 = false, sanyi2 = false, sanyi3 = false;
	char cmap[12][5], cmap1[12][5];
	int k, k1, k2, k3, i2, j2;
	int allmove1[200][2], allmove2[200][2];
	int x = 0;
	int i3, j3;
	int flag = 0, flag1, flag2 = 0;
	FILE *fp;
	fp = fopen("1", "a");
	for (i2 = 0; i2<12; i2++)
	{
		for (j2 = 0; j2<5; j2++)
			cmap[i2][j2] = cMap[i2][j2];
	}
	cmap[i1][j1] = cmap[i][j];
	cmap[i][j] = '0';

	if (dz[1][11] == 0)
		cMap[0][3] = 'L';
	if (dz[3][11] == 0)
		cMap[0][1] = 'L';
	//    纰板啗鏃�        銆傘�傘�傘�傘�傘�傘�傘�傘�傘�傘�傘�傘�傘�傘�傘�傘�傘�傘�傘�傘�傘�傘�傘�傘�傘�傘�傘�傘��

	mychessdx(cMap, mchess);
	if (cMap[i][j] <= 'e' || cMap[i][j] == 'k')//宸辨柟鐨勫ぇ浜庢梾闀跨殑妫嬪瓙锛屽拰鐐稿脊涓嶇宸辨柟澶ф湰钀ョ殑妫嬪瓙
	{
		if (cMap[11][1] == 'l' && i1 == 11 && j1 == 3)
			teshu = teshu - 20000;
		if (cMap[11][3] == 'l' && i1 == 11 && j1 == 1)
			teshu = teshu - 20000;
	}
	fprintf(fp, "\n宸辨柟鐨勫ぇ浜庢梾闀跨殑妫嬪瓙锛屽拰鐐稿脊涓嶇宸辨柟澶ф湰钀ョ殑妫嬪瓙 %d ", teshu);
	////////////////////////////////////////////////////淇濇姢鍐涙棗

	if (cMap[11][1] == 'l')
	{
		if (cMap[10][1] == 'X' && i1 == 10 && j1 == 1)
			teshu = teshu + (13 - (cMap[i][j] - 'a')) * 500;
		if (cMap[10][0] == 'X' && cMap[11][0] == '0' && i1 == 10 && j1 == 0)
			teshu = teshu + (13 - (cMap[i][j] - 'a')) * 500;
		if (cMap[10][0] == 'X' && cMap[11][0] == 'j' && Judge(10, 0, 8, dz)>6000)
			teshu = teshu + (13 - (cMap[i][j] - 'a')) * 500;
	}
	if (cMap[11][3] == 'l')
	{
		if (cMap[10][3] == 'X' && i1 == 10 && j1 == 3)
			teshu = teshu + (13 - (cMap[i][j] - 'a')) * 500;
		if (cMap[10][4] == 'X' && cMap[11][4] == '0' && i1 == 10 && j1 == 4)
			teshu = teshu + (13 - (cMap[i][j] - 'a')) * 500;
		if (cMap[10][4] == 'X' && cMap[11][4] == 'j' && Judge(10, 4, 8, dz)>6000)
			teshu = teshu + (13 - (cMap[i][j] - 'a')) * 500;
	}
	fprintf(fp, "\n淇濇姢鍐涙棗褰卞搷鍚庣殑鐗规畩鍒� %d ", teshu);
	/////////////////////////////////////////////////////////////////
	//鐗规畩琛屾
//*************************************
//5.浣嶄簬涓矾閾佽建鐨勬瀛愮洿鎺ュ鏁屾柟绌虹己琛岃惀鐨勬敾鍑�     
/*int step = 0;//555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555
if (IsFilledCamp(cMap, 4, 1) == 0 && IsFilledCamp(cMap, 4, 3) == 0)
{
	if (IsMyChess(cMap, 6, 2) == 1 && i1 == 5 && j1 == 2)
	{
		teshu = teshu + 100000;
		step++;
	}
}
if (IsMyChess(cMap, 5, 2) == 1)
{
	if (IsOppChess(cMap, 5, 1) == 1 && i1 == 5 && j1 == 1)
		teshu = teshu + 50000;
}
if (IsMyChess(cMap, 5, 1) == 1)
{
	if (IsOppChess(cMap, 5, 0) == 1 && i1 == 5 && j1 == 0)
		teshu = teshu + 50000;
}
*/
//6.閽堝澶т紭鍔跨偢寮圭殑鍒╃敤  (闃叉鐐稿脊鍥炶惀涓嶅姩锛�
/*int nomovechess = 2;
int leishu = 3;
if (IsMyChess(cMap, 0, 1) == 1 || IsMyChess(cMap, 0, 3) == 1)
nomovechess--;
nomovechess ==nomovechess+ leishu;*/
if (NumChess(cMap) - NumOppChess(cMap) >= 6)  //鍏锋湁杈冨ぇ浼樺娍
{
	int boom = 0;//鐐稿脊鏁伴噺
	for (i = 0; i < 12; i++)
		for (j = 0; j < 5; j++)
			if (cMap[i][j] == 'k')
				boom++;

	if (cMap[7][3] == 'k'&& cMap[7][1] == 'k')  //寮哄埗鐐稿脊鍑鸿钀�(鎴戞柟涓や釜鐐稿脊閮藉瓨鍦級
	{
		int flag = 0;    //鍒ゆ柇鏈�浼樼偢寮瑰嚭琛岃惀浣嶇疆
		int oppnum = 0;  //鍒ゆ柇鐐稿脊鍓嶈繘鐨勮矾绾跨殑鏁屾柟鏁伴噺
		int oppnum1[10][2], oppnum2[10][2], oppnum3[10][2], m = 0;
		for (j = 0; j < 4; j++)
		{
			if (IsOppChess(cMap, 6, j) == 1)
			{
				oppnum++;
				oppnum1[m][0] = i;
				oppnum1[m][1] = j;
				m++;
			}

		}
		if (oppnum == 1)
		{
			if (Judge(oppnum1[0][0], oppnum1[0][1], 0, dz)>=6000)
			{
				if (oppnum1[0][1] <= 2)
					if (IsMyChess(cMap, 7, 1) == 1 && i1 == oppnum1[0][0] && j1 == oppnum1[0][1])
						teshu = teshu + 5000;
				if (oppnum1[0][1] > 2)
					if (IsMyChess(cMap, 7, 3) == 1 && i1 == oppnum1[0][0] && j1 == oppnum1[0][1])
						teshu = teshu + 5000;
			}
			if (Judge(oppnum1[0][0], oppnum1[0][1], 1, dz)>=6000)
			{
				if (oppnum1[0][1] <= 2)
					if (IsMyChess(cMap, 7, 1) == 1 && i1 == oppnum1[0][0] && j1 == oppnum1[0][1])
						teshu = teshu + 5000;
				if (oppnum1[0][1] > 2)
					if (IsMyChess(cMap, 7, 3) == 1 && i1 == oppnum1[0][0] && j1 == oppnum1[0][1])
						teshu = teshu + 5000;
			}
		}
		m = 0;
		oppnum = 0;
		flag = 0;
		for (i = 9; i >= 1; i--)
		{
			if (IsOppChess(cMap, i, 0) == 1)
			{
				oppnum++;
				oppnum2[m][0] = i;
				oppnum2[m][1] = j;
				m++;
			}
		}
		k = Oppnextmove(oppnum2[0][0], oppnum2[0][1], cMap, allmove2);
		for (k1 = 0; k1 < k; k1++)
			if (cMap[allmove2[k1][0]][allmove2[k1][1]] == 'l')
				flag = 1;  //鍒ゆ柇瀵规柟宸︿晶妫嬪瓙瀵规垜鏂瑰啗鏃楁槸鍚﹀瓨鍦ㄧ潃濞佽儊
		if (flag == 0 && IsMyChess(cMap, 9, 1) == 1)
		{
			if (Judge(oppnum2[0][0], oppnum2[0][1], 0, dz) >= 6000)
			{
				if (oppnum2[0][0] == 6 || oppnum2[0][0] == 7 || oppnum2[0][0] == 8)
				{
					if (IsMyChess(cMap, 7, 1) == 1 && i1 == oppnum2[0][0] && j1 == 0)
						teshu = teshu + 5000;
				}
				else
				{
					if (IsMyChess(cMap, 7, 1) == 1 && i1 == 7 && j1 == 0)
						teshu = teshu + 4000;
				}
			}
			if (Judge(oppnum2[0][0], oppnum2[0][1], 1, dz) >= 6000)
			{
				if (oppnum2[0][0] == 6 || oppnum2[0][0] == 7 || oppnum2[0][0] == 8)
				{
					if (IsMyChess(cMap, 7, 1) == 1 && i1 == oppnum2[0][0] && j1 == 0)
						teshu = teshu + 5000;
				}
				else
				{
					if (IsMyChess(cMap, 7, 1) == 1 && i1 == 7 && j1 == 0)
						teshu = teshu + 4000;
				}
			}
		}

		m = 0;
		oppnum = 0;
		flag = 0;
		for (i = 9; i >= 1; i--)
		{
			if (IsOppChess(cMap, i, 4) == 1)
			{
				oppnum++;
				oppnum2[m][0] = i;
				oppnum2[m][1] = j;
				m++;
			}
		}
		k = Oppnextmove(oppnum2[0][0], oppnum2[0][1], cMap, allmove2);
		for (k1 = 0; k1 < k; k1++)
			if (cMap[allmove2[k1][0]][allmove2[k1][1]] == 'l')
				flag = 1;  //鍒ゆ柇瀵规柟鍙充晶妫嬪瓙瀵规垜鏂瑰啗鏃楁槸鍚﹀瓨鍦ㄧ潃濞佽儊
		if (flag == 0 && IsMyChess(cMap, 9, 3) == 1)
		{
			if (Judge(oppnum2[0][0], oppnum2[0][1], 0, dz) >= 6000)
			{
				if (oppnum2[0][0] == 6 || oppnum2[0][0] == 7 || oppnum2[0][0] == 8)
				{
					if (IsMyChess(cMap, 7, 3) == 1 && i1 == oppnum2[0][0] && j1 == 4)
						teshu = teshu + 5000;
				}
				else
				{
					if (IsMyChess(cMap, 7, 3) == 1 && i1 == 7 && j1 == 4)
						teshu = teshu + 4000;
				}
			}
			if (Judge(oppnum2[0][0], oppnum2[0][1], 1, dz) >= 6000)
			{
				if (oppnum2[0][0] == 6 || oppnum2[0][0] == 7 || oppnum2[0][0] == 8)
				{
					if (IsMyChess(cMap, 7, 3) == 1 && i1 == oppnum2[0][0] && j1 == 4)
						teshu = teshu + 5000;
				}
				else
				{
					if (IsMyChess(cMap, 7, 3) == 1 && i1 == 7 && j1 == 4)
						teshu = teshu + 4000;
				}
			}
		}
	

	/*for (i = 1; i <= 9; i++)
	{
		if (IsOppChess(cMap, i, 0) == 1 && Judge(i, 0, 0, dz) > 7000)
			flag = 2;
		if (IsOppChess(cMap, i, 0) == 1 && Judge(i, 0, 1, dz) > 7000)
			flag = 2;
		if (flag == 2 && j1 == 0)
			teshu = teshu + 3500;
	}
	if (IsMyChess(cMap, 7, 3) == 1 && cMap[7][3] == 'k')  //寮哄埗鐐稿脊鍑鸿钀�
	{
		int flag = 0;
		for (j = 0; j < 4; j++)
		{
			if (IsOppChess(cMap, 6, j) == 1 && Judge(6, j, 0, dz) > 8000)
				flag = 1;
			if (IsOppChess(cMap, 6, j) == 1 && Judge(6, j, 1, dz) > 8000)
				flag = 1;
		}
		if (flag == 1 && i1 == 6)
			teshu = teshu + 2000;
		for (i = 1; i <= 9; i++)
		{
			if (IsOppChess(cMap, i, 4) == 1 && Judge(i, 4, 0, dz) > 8000)
				flag = 2;
			if (IsOppChess(cMap, i, 4) == 1 && Judge(i, 4, 1, dz) > 8000)
				flag = 2;
		}
		if (flag == 2 && j1 == 4)
			teshu = teshu + 2500;
	}*/
	if (boom != 0)  //鐐稿脊涓诲姩鍑哄嚮
	{
		flag = 0;
		for(i=0;i<12;i++)
			for (j = 0; j < 5; j++)
			{
				if(cMap[i][j]='k')
					if ((i != 7 && j != 1) && (i != 7 && j != 3) && (i != 8 && j != 2) && (i != 9 && j != 1) && (i != 9 && j != 3))
					{
						flag = 1;
					}
			}
		if(flag==1)
			for (i = 0; i<12; i++)
				for (j = 0; j < 5; j++)
					if (IsOppChess(cMap, i, j) == 1)
					{
						k1 = Oppnextmove(i, j, cMap, allmove2);
						for (k1 = 0; k1 < k; k1++)
						{
							if (cMap[allmove2[k1][0]][allmove2[k1][1]] == 'k')
								if (Judge(i, j, 0, dz) >= 5000 && i1 == 1 && j1 == j)
									teshu = teshu + 5000;
							if (cMap[allmove2[k1][0]][allmove2[k1][1]] == 'k')
								if (Judge(i, j, 1, dz) >= 5000 && i1 == 1 && j1 == j)
									teshu = teshu + 5000;
						}
					}
		/*for (i = 0; i < 12; i++)
			for (j = 0; j < 5; j++)
			{
				if (cMap[i][j] == 'k'&&i1 == 7, j1 == 1)
					teshu = teshu - 5000;
				if (cMap[i][j] == 'k'&&i1 == 7, j1 == 3)
					teshu = teshu - 5000;
				if (cMap[i][j] == 'k'&&i1 == 9, j1 == 1)
					teshu = teshu - 5000;
				if (cMap[i][j] == 'k'&&i1 == 9, j1 == 3)
					teshu = teshu - 5000;
				for (i2 = 0; i2 < 12; i2++)                         //鍑虹幇鐐稿脊璁╄惀鏃朵細澶哄洖琛岃惀
					for (j2 = 0; j2 < 5; j2++)
					{
						k = Oppnextmove(i, j, cMap, allmove2);
						for (k1 = 0; k1 <= k; k1++)
						{

							if (i1 == 7 && j1 == 1)
								teshu = teshu + 6000;
							if (i1 == 7 && j1 == 3)
								teshu = teshu + 6000;
							if (i1 == 9 && j1 == 1)
								teshu = teshu + 6000;
							if (i1 == 9 && j1 == 3)
								teshu = teshu + 6000;
						}
					}
			}*/

	}
	}
	if (IsMyChess(cMap, 7, 1) && cMap[7][1] == 'k'&&j1 == 0)  //鏁屾柟鍐涢暱鍙镐护鍑虹幇鍦ㄥ乏鍙充袱渚х殑鐐稿脊璺熻釜
	{
		for (i = 1; i < 11; i++)
		{
			if (IsOppChess(cMap, i, 0) == 1 && Judge(i, 0, 0, dz) > 6000)
				teshu = teshu + 3000;
			if (IsOppChess(cMap, i, 0) == 1 && Judge(i, 0, 1, dz) > 6000)
				teshu = teshu + 3000;

		}
	}
	if (IsMyChess(cMap, 7, 3) && cMap[7][3] == 'k'&&j1 == 4)
	{
		for (i = 1; i < 11; i++)
		{
			if (IsOppChess(cMap, i, 4) == 1 && Judge(i, 4, 0, dz) > 6000)
				teshu = teshu + 3000;
			if (IsOppChess(cMap, i, 4) == 1 && Judge(i, 4, 1, dz) > 6000)
				teshu = teshu + 3000;

		}
	}
	if (IsMyChess(cMap, 7, 1) == 1 && cMap[7][1] == 'k'&&i1 == 6)
		for (j = 0; j < 4; j++)
		{
			if (IsOppChess(cMap, 6, j) == 1 && Judge(6, 4, 0, dz) > 6000)
				teshu = teshu + 3500;
			if (IsOppChess(cMap, 6, j) == 1 && Judge(6, 4, 1, dz) > 6000)
				teshu = teshu + 3500;
		}
	//7.鏁屾柟鍐涙棗鏆撮湶鐨勮繘鏀�  
	if (NumOppChess(cMap) <= 10)
	{
		if (cMap[0][1] == 'L')
		{
			k = nextmove1(i1, j1, cMap, allmove1);
			for (k1 = 0; k1 < k; k++)
			{
				if (allmove1[k][0] == 1 && allmove1[k][1] == 1)
					teshu = teshu + 20000;
				if (allmove1[k][0] == 0 && allmove1[k][1] == 1)
					teshu = teshu + 30000;
			}
		}
		if (cMap[0][3] == 'L')
		{

			k = nextmove1(i1, j1, cMap, allmove1);
			for (k1 = 0; k1 < k; k++)
			{
				if (allmove1[k][0] == 1 && allmove1[k][1] == 3)
					teshu = teshu + 20000;
				if (allmove1[k][0] == 0 && allmove1[k][1] == 3)
					teshu = teshu + 30000;
			}
		}

	}
	//妯℃嫙澶烘棗
	if (NumOppChess(cMap) <= 10)
	{
		if (cMap[0][1] == 'L')
		{
			k = nextmove1(i1, j1, cMap, allmove1);
			for (k1 = 0; k1 < k; k++)
			{
				if (allmove1[k][0] == 1 && allmove1[k][1] == 1)
					teshu = teshu + 20000;
				if (allmove1[k][0] == 0 && allmove1[k][1] == 1)
					teshu = teshu + 30000;
			}
		}
		if (cMap[0][3] == 'L')
		{

			k = nextmove1(i1, j1, cMap, allmove1);
			for (k1 = 0; k1 < k; k++)
			{
				if (allmove1[k][0] == 1 && allmove1[k][1] == 3)
					teshu = teshu + 20000;
				if (allmove1[k][0] == 0 && allmove1[k][1] == 3)
					teshu = teshu + 30000;
			}
		}

	}
	// 6.寮哄埗澶烘棗                          ////////////////////////////////////////5555555555555555555555555
	
	//2姝�
	if (cMap[0][1] == 'L')
	{
		if (cMap[i1][j1] == '0'&&i1 == 0 && (j1 == 0 || j1 == 2))
			teshu += 5000;//璧颁笅杈硅姣旇蛋閾佽建鏈変紭鍔�
		else if (i1 == 1 && j1 == 1)
			teshu += 3500;//濡傛灉涓嬭竟鏈夊瓙璧板彸杈�
		else if (j1 == 0)
			teshu += 2500;//闈犺繎閾佽建
	}
	else if (cMap[0][3] == 'L')
	{
		if (cMap[i1][j1] == '0'&&i1 == 0 && (j1 == 4 || j1 == 2))
			teshu += 5000;//璧颁笅杈硅姣旇蛋閾佽建鏈変紭鍔�
		else if (i1 == 1 && j1 == 1)
			teshu += 3500;//濡傛灉涓嬭竟鏈夊瓙璧板彸杈�
		else if (cMap[0][3] == 'L'&&j1 == 4)
			teshu += 2500;//闈犺繎閾佽建
	}
	//1姝�
	if (cMap[i1][j1] == 'L')
		teshu += 100000;
	//鎴戞柟闈炲墠浜屽ぇ鐨勫瓙鍙互鍘昏瘯鎺竴涓嬭钀ュ唴鏄惁涓哄啗鏃�
	//琚墦鏂簡銆傚厛鍐欏埆鐨�
	//2.鎴戞柟鏈�澶ф瀛愬畧鎶ゅ啗妫�
	if ((cMap[i][j] == 'a'&&i >= 8 && j >= 2) || (mchess[0] != 'a'))
	{
		if (cMap[i][j] == mchess[0])
		{
			if (cMap[i1][j1] == 'X' && Judge(i1, j1, 10, dz) >= 3000)
				teshu = teshu - 5000;
			if (cMap[11][1] == 'l')
			{
				if (cMap[10][2] == mchess[0] || cMap[10][1] == mchess[0] || cMap[10][0] == mchess[0] || cMap[9][2] == mchess[0] || cMap[9][1] == mchess[0] || cMap[9][0] == mchess[0] || cMap[8][0] == mchess[0] || cMap[8][1] == mchess[0])
					flag2 = 1;		//鍒ゆ柇宸辨柟妫嬪瓙鏄惁鍦ㄥ彲浠ヤ繚鎶ゅ啗妫嬬殑浣嶇疆 1鍦ㄣ��0涓嶅湪
				if (i1 == 10 && j1 == 2 && cMap[i1][j1] == 'X')
					teshu = teshu + 5000;
				else if (i1 == 10 && j1 == 1 && cMap[i1][j1] == 'X')
					teshu = teshu + 15000;
				else if ((i1 == 9 || i1 == 8 || i1 == 10) && j1 == 0 && cMap[i1][j1] == 'X')
				{
					for (k1 = i1 - 1; k1 >= 1; k1--)
					{
						if (cMap[k1][j1] == '0')
							continue;
						else if (cMap[k1][j1] == 'X' && Judge(k1, j1, 10, dz) >= 3000)
						{
							flag = 1;
							break;
						}
						else
							break;
					}
					if (flag == 1)
						teshu = teshu - 5000;
					else
						teshu = teshu + 2000;
					if (cMap[10][0] == 'X')
						teshu = teshu + 5000;
				}
				else if (i1 == 8 && j1 == 1 && cMap[i1][j1] == 'X')
					teshu = teshu + 3500;
				else if (i1 == 9 && j1 == 2 && cMap[i1][j1] == 'X')
					teshu = teshu + 3500;
				else if (i1 == 9 && j1 == 1)
					teshu = teshu + 3000;
				else
					teshu = teshu - 2000;
			}
			if (cMap[11][3] == 'l')
			{
				if (cMap[10][2] == mchess[0] || cMap[10][3] == mchess[0] || cMap[10][4] == mchess[0] || cMap[9][2] == mchess[0] || cMap[9][3] == mchess[0] || cMap[9][4] == mchess[0] || cMap[8][3] == mchess[0] || cMap[8][4] == mchess[0])
					flag2 = 1;
				if (i1 == 10 && j1 == 2 && cMap[i1][j1] == 'X')
					teshu = teshu + 5000;
				else if (i1 == 10 && j1 == 3 && cMap[i1][j1] == 'X')
					teshu = teshu + 15000;
				else if (i1 == 9 && j1 == 3)
					teshu = teshu + 3000;
				else if ((i1 == 9 || i1 == 8 || i1 == 10) && j1 == 4 && cMap[i1][j1] == 'X')
				{
					for (k1 = i1 - 1; k1 >= 1; k1--)
					{
						if (cMap[k1][j1] == '0')
							continue;
						else if (cMap[k1][j1] == 'X' && Judge(k1, j1, 10, dz) >= 3000)
						{
							flag = 1;
							break;
						}
						else
							break;
					}
					if (flag == 1)
						teshu = teshu - 5000;
					else
						teshu = teshu + 2000;
					if (cMap[10][4] == 'X')
						teshu = teshu + 5000;

				}
				else if (i1 == 8 && j1 == 3 && cMap[i1][j1] == 'X')
					teshu = teshu + 3500;
				else if (i1 == 9 && j1 == 2 && cMap[i1][j1] == 'X')
					teshu = teshu + 3500;
				else
					teshu = teshu - 2000;
			}
		}

		if (flag2 == 0 && cMap[i][j] == mchess[0])//宸辨柟鏈�澶ф瀛愪笉鍦ㄥ啗鏃楀懆鍥达紝灏嗘瀛愯蛋杩囧幓
		{
			sanyi1 = false;
			sanyi2 = false;
			sanyi3 = false;
			if (cMap[11][1] == 'l')
			{

				if (i1 == 10 && (j1 == 2 || j1 == 1 || j1 == 0))
				{
					teshu = teshu + 6000;
					sanyi1 = true;
				}
				if (i1 == 9 && j1 == 1)
				{
					teshu = teshu + 6000;
					sanyi1 = true;
				}
			}
			if (cMap[11][3] == 'l')
			{
				if (i1 == 10 && (j1 == 2 || j1 == 3 || j1 == 4))
				{
					teshu = teshu + 6000;
					sanyi1 = true;
				}
				if (i1 == 9 && j1 == 3)
				{
					teshu = teshu + 6000;
					sanyi1 = true;
				}
			}
			if (sanyi1 == false)
			{
				k1 = nextmove1(i1, j1, cmap, allmove1);
				for (k2 = 0; k2 < k1; k2++)
				{
					if (cMap[11][1] == 'l')
					{
						if (allmove1[k2][0] == 10 && (allmove1[k2][1] == 2 || allmove1[k2][1] == 1 || allmove1[k2][1] == 0))
						{
							teshu = teshu + 5000;
							sanyi2 = true;
						}
						if (allmove1[k2][0] == 9 && allmove1[k2][1] == 1)
						{
							teshu = teshu + 5000;
							sanyi2 = true;
						}
					}

					if (cMap[11][3] == 'l')
					{
						if (allmove1[k2][0] == 10 && (allmove1[k2][1] == 2 || allmove1[k2][1] == 3 || allmove1[k2][1] == 4))
						{
							teshu = teshu + 4000;
							sanyi2 = true;
						}
						if (allmove1[k2][0] == 9 && allmove1[k2][1] == 3)
						{
							teshu = teshu + 4000;
							sanyi2 = true;
						}
					}
				}
				if (sanyi2 == false)
				{
					for (k2 = 0; k2 < k1; k2++)
					{
						cmap[allmove1[k2][0]][allmove1[k2][1]] = cmap[i1][j1];
						cmap[i1][j1] = '0';
						k3 = nextmove1(allmove1[k2][0], allmove1[k2][1], cmap, allmove2);
						for (int k4 = 0; k4 < k3; k4++)
						{
							if (cMap[11][1] == 'l')
							{
								if (allmove2[k4][0] == 10 && (allmove2[k4][1] == 2 || allmove2[k4][1] == 1 || allmove2[k4][1] == 0))
								{
									teshu = teshu + 4000;
									sanyi2 = true;
								}
								if (allmove2[k4][0] == 9 && allmove2[k4][1] == 1)
								{
									teshu = teshu + 4000;
									sanyi2 = true;
								}
							}
							if (cMap[11][3] == 'l')
							{
								if (allmove2[k4][0] == 10 && (allmove2[k4][1] == 2 || allmove2[k4][1] == 3 || allmove2[k4][1] == 4))
								{
									teshu = teshu + 4000;
									sanyi2 = true;
								}
								if (allmove2[k4][0] == 9 && allmove2[k4][1] == 3)
								{
									teshu = teshu + 4000;
									sanyi2 = true;
								}
							}
							cmap[i1][j1] = cmap[allmove1[k2][0]][allmove1[k2][1]];
							cmap[allmove1[k2][0]][allmove1[k2][1]] = '0';
						}
					}
				}

			}

		}
	}
	fprintf(fp, "\n鏈�澶у瓙绉诲姩褰卞搷鍚庣殑鐗规畩鍒嗗�� %d ", teshu);

	//3.涓夊崄涓�姝ワ紝鐐稿脊璺熼殢濂楄矾
	if (Ina_step[0] == 2 && Ina_step[1]>12 && Ina_step[1] <= 18)
	{


		if (cMap[i][j] >= 'e' && cMap[i][j] < 'i')
		{
			k1 = nextmove1(i1, j1, cmap, allmove1);	//鍒ゆ柇妫嬬洏涓婏紝宸辨柟澶т簬宸ュ叺灏忎簬鏃呴暱鐨勬瀛愯兘鍚﹀湪涓ゆ涔嬪唴纰板瓙锛�
			for (k2 = 0; k2 < k1; k2++)
			{
				if (cmap[allmove1[k2][0]][allmove1[k2][1]] >= 'A' && cmap[allmove1[k2][0]][allmove1[k2][1]] <= 'X')
					flag = 1;
			}
		}
		if (cMap[i1][j1] >= 'A' && cMap[i1][j1] <= 'X')
		{
			if (!IsMoveCamp(i, j) && cMap[i][j] >= 'e' && cMap[i][j] < 'i')//宸辨柟涓嶅啀琛岃惀涓斿皬浜庢梾闀垮ぇ浜庢帓闀跨殑妫嬪瓙銆傜瀛愮殑鍒嗗�兼渶澶�
			{
				sanyif = 30000;
				sanyif = sanyif + (cMap[i][j] - 'a') * 10;
				sanyi1 = true;
			}
			else if (cMap[i][j] == mchess[0])//宸辨柟宸ュ叺涓嶅弬涓庝笁鍗佷竴姝ワ紝宸辨柟鏈�澶ф瀛愪笉鍙備笌涓夊崄涓�姝�
			{
				sanyif = 0;
				sanyi1 = false;
			}
			else if (cMap[i][j] == 'i')
			{
				if (walei(cMap, dz))//鍒ゆ柇宸ュ叺鏄惁闇�瑕佹寲闆凤紝涓嶉渶瑕佸垯锛岃繘琛屻�備笁鍗佷竴姝�
				{
					sanyi1 = true;
					sanyif = 40000;                     //////////////////////////////////////////
														//sanyif=sanyif+(cMap[i][j]-'a')*10;
				}
				else
				{
					sanyif = 0;
					sanyi1 = false;
				}
			}
			else if (IsMoveCamp(i, j) && weixie(i, j, i1, j1, dz, cMap) < 0)//宸辨柟鍦ㄨ钀ョ殑妫嬪瓙	cMap[i][j]<'d'
			{
				sanyif = 20000;
				sanyif = sanyif + (cMap[i][j] - 'a') * 10;
				sanyi1 = false;
			}
			else if (cMap[i][j] == 'k')//宸辨柟鍦ㄨ钀ュ皬浜庢梾闀跨殑妫嬪瓙	cMap[i][j]<'d'
			{
				sanyif = 20000;
				sanyif = sanyif + (cMap[i][j] - 'a') * 10;
				sanyi1 = false;
			}
			else//宸辨柟澶т簬鍥㈤暱鐨勬瀛�
			{
				sanyi1 = true;
				sanyif = 28000;
				if (Judge(i1, j1, 9, dz) > 4000)
				{
					sanyif = 20000;
					sanyi1 = false;
				}
				sanyif = sanyif + (cMap[i][j] - 'a') * 10;

			}
			//
		}
		if (sanyi1 == false)//绗簩姝ヨ兘纰板埌瀛�
		{
			k1 = nextmove1(i1, j1, cmap, allmove1);
			for (k2 = 0; k2 < k1; k2++)
				if (cmap[allmove1[k2][0]][allmove1[k2][1]] >= 'A' && cmap[allmove1[k2][0]][allmove1[k2][1]] <= 'X')
				{
					sanyi2 = true;
					if (cMap[i][j] == mchess[0])//宸辨柟宸ュ叺涓嶅弬涓庝笁鍗佷竴姝ワ紝宸辨柟鏈�澶ф瀛愪笉鍙備笌涓夊崄涓�姝�
					{
						sanyif = 0;
						sanyi2 = false;
					}
					else if (cMap[i][j] == 'i')
					{
						if (walei(cMap, dz))//鍒ゆ柇宸ュ叺鏄惁闇�瑕佹寲闆凤紝涓嶉渶瑕佸垯锛岃繘琛屻�備笁鍗佷竴姝�
						{
							sanyif = 28000;                   ///////////////////////////////
															  //sanyif=sanyif+(cMap[i][j]-'a')*10;
						}
						else
							sanyif = 0;
					}
					else if (cMap[i][j] == 'k')
					{
						sanyif = 15000;
						sanyif = sanyif + (cMap[i][j] - 'a') * 10;
					}
					else if (cMap[i][j] >= 'e' && cMap[i][j] < 'i')
					{
						sanyif = 25000;
						sanyif = sanyif + (cMap[i][j] - 'a') * 10;
					}
					else//宸辨柟澶т簬鍥㈤暱鐨勬瀛�
					{
						sanyif = 23000;
						if (Judge(allmove1[k2][0], allmove1[k2][1], 9, dz) > 4000)
						{
							sanyif = 15000;
							sanyi2 = false;
						}
						sanyif = sanyif + (cMap[i][j] - 'a') * 10;
					}

				}
			if (sanyi2 == false && flag == 0)				//绗笁姝ヨ兘纰板瓙
			{
				for (k2 = 0; k2 < k1; k2++)
				{
					cmap[allmove1[k2][0]][allmove1[k2][1]] = cmap[i1][j1];
					cmap[i1][j1] = '0';
					k3 = nextmove1(allmove1[k2][0], allmove1[k2][1], cmap, allmove2);
					for (int k4 = 0; k4 < k3; k4++)
						if (cmap[allmove2[k4][0]][allmove2[k4][1]] >= 'A' && cmap[allmove2[k4][0]][allmove2[k4][1]] <= 'X')
						{
							if (cMap[i][j] >= 'e' && cMap[i][j] < 'i')
							{
								sanyif = 20000;
								sanyif = sanyif + (cMap[i][j] - 'a') * 10;
							}
							else if (cMap[i][j] == mchess[0])
								sanyif = 0;
							else if (cMap[i][j] == 'i')
							{
								if (walei(cMap, dz))//鍒ゆ柇宸ュ叺鏄惁闇�瑕佹寲闆凤紝涓嶉渶瑕佸垯杩涜銆備笁鍗佷竴姝�
								{
									sanyif = 22000;                  //////////////////////////////////////
									sanyif = sanyif + (cMap[i][j] - 'a') * 10;
								}
								else
									sanyif = 0;
							}
							else
							{
								sanyif = 13000;
								sanyif = sanyif + (cMap[i][j] - 'a') * 10;
							}
							sanyi3 = true;

						}
					cmap[i1][j1] = cmap[allmove1[k2][0]][allmove1[k2][1]];
					cmap[allmove1[k2][0]][allmove1[k2][1]] = '0';
				}
			}
		}

		if (NumChess(cMap) < 8 && NumOppChess(cMap) < 8)
			if (cMap[i][j] == 'k')
				sanyif = sanyif + 20000;
		score1 = sanyif + teshu;

	}
	fprintf(fp, "\n涓変竴姝ュ奖鍝嶄笁涓�鍒� %d ", sanyif);
	if (Ina_step[0] == 2 && Ina_step[1]>18)
	{
		k1 = nextmove1(i1, j1, cmap, allmove1);
		for (k2 = 0; k2<k1; k2++)
		{
			if ((allmove1[k2][1] == 0 || allmove1[k2][1] == 4) && (allmove1[k2][0]>0 && allmove1[k2][0]<11))
				sanyif = 25000;
		}
		if (i1>0 && i1<11 && (j1 == 0 || j1 == 4))
			sanyif = 35000;
		if ((j == 0 || j == 4) && (i>0 && i<11))
		{
			if (i1 == 1 && (j1 == 0 || j1 == 4))
				sanyif = 45000;
		}

		if (cMap[i1][j1] == 'X')
		{
			sanyif = 60000;
			if (Judge(i1, j1, 9, dz)>3000)
				sanyif = sanyif - 10000;
		}
		if (((i1 == 1 && (j1 == 1 || j1 == 3)) || (i1 == 0 && (j1 == 0 || j1 == 4))) && Judge(i1, j1, 9, dz)<50)
			sanyif = 55000;
		if (cMap[i][j] == 'k')
			sanyif = sanyif - 1000;
		if ((Judge(1, 1, 9, dz)<50 || Judge(0, 0, 9, dz)<50) && j1 == 0)
			sanyif = sanyif + 500;
		if ((Judge(1, 3, 9, dz)<50 || Judge(0, 4, 9, dz)<50) && j1 == 4)
			sanyif = sanyif + 500;
		if (cMap[0][1] == 'L' && i1 == 1 && j1 == 1)
			sanyif = sanyif + 2000;
		if (cMap[0][3] == 'L' && i1 == 1 && j1 == 3)
			sanyif = sanyif + 2000;
		if (cMap[i][j]>mchess[0] && cMap[i][j]<'j')
			sanyif = sanyif + (cMap[i][j] - 'a') * 10;
		if (NumChess(cMap) < 8 && NumOppChess(cMap) < 8)
			if (cMap[i][j] == 'k')
				sanyif = sanyif + 20000;
		score1 = sanyif + teshu;
	}

	if (Ina_step[0] == 1 && Ina_step[1]>12) //鏁屾柟鐨勪笁鍗佷竴姝ヨ繘琛岃翰闂�
	{
		if (cMap[i][j] != mchess[0] && cMap[i1][j1] != 'X')
		{
			for (int m = 0; m<12; m++)
			{
				for (int n = 0; n<5; n++)
				{
					if (Judge(m, n, 9, dz)<5000)
					{
						k1 = Oppnextmove(m, n, cMap, allmove1);
						for (k2 = 0; k2<k1; k2++)
						{
							if (allmove1[k2][0] == i && allmove1[k2][1] == j)
								sanyi1 = true;
						}
					}
				}
			}
			for (int m = 0; m<12; m++)
			{
				for (int n = 0; n<5; n++)
				{
					if (Judge(m, n, 9, dz)<5000)
					{
						k1 = Oppnextmove(m, n, cmap, allmove1);
						for (k2 = 0; k2<k1; k2++)
						{
							if (allmove1[k2][0] == i1 && allmove1[k2][1] == j1)
								sanyi2 = true;
						}
					}
				}
			}
			if (sanyi1 == false && sanyi2 == false)
			{
				if (IsMoveCamp(i1, j1) == 1)
					sanyif = 4000;
				else
					sanyif = 3000;
			}
		}
	}
	fprintf(fp, "\n鏁屾柟涓変竴姝ヨ翰闂奖鍝嶅悗鐨勪笁涓� 鍒� %d ", sanyif);
	jushipg(cMap, dz);    //鏀瑰彉妫嬬洏鐨勫垎鍊�

	//3.鐐稿脊淇濇姢鍜屼娇鐢�
	if (cMap[i][j] == 'k')
	{
		if (cMap[i][j] == 'k')
		{
			if (i == 8 && j == 3)
			{
				if (i1 == 9 && j == 3)
					teshu -= 10000;
				else if (i1 == 8 && j1 == 2)
					teshu -= 10000;
				else if (i1 == 7 && j1 == 3 && cMap[6][4] == 'a')
					teshu -= 100000;
			}
		}
		///////////// 琛ュ厖鐐稿脊鐢ㄦ硶
		int  NextNumberOfSteps = nextmove1(i1, j1, cmap, allmove1);
		char mc[25];
		mychessdx(cMap, mc);
		if (Judge(i1, j1, 0, dz) > 6000 || Judge(i1, j1, 1, dz) > 6000 || Judge(i1, j1, mc[0] - 'a', dz) > 6000 || Judge(i1, j1, mc[1] - 'a', dz) > 6000 || Judge(i1, j1, mc[2] - 'a', dz) > 6000)
		{
			if (cMap[i][j] == 'k')
			{
				fp = fopen("1", "a");
				fprintf(fp, "\n鐐稿脊鐐镐簡鏁屾柟杈冨ぇ妫嬪瓙");
				fclose(fp);
				return 800000;
			}
		}
		else
		{
			for (int ii = 0; ii != NextNumberOfSteps; ii++)
			{
				int temp1 = allmove1[ii][0], temp2 = allmove1[ii][1];
				if (Judge(i1, j1, 0, dz) > 6000 || Judge(i1, j1, 1, dz) > 6000 || Judge(temp1, temp2, mc[0] - 'a', dz) > 6000 || Judge(temp1, temp2, mc[1] - 'a', dz) > 6000 || Judge(temp1, temp2, mc[2] - 'a', dz) > 6000)
					if (cMap[i][j] == 'k')
					{
						fp = fopen("1", "a");
						fprintf(fp, "\n鐐稿脊妯℃嫙涓ゆ鐐告帀鏁屾柟杈冨ぇ妫嬪瓙");
						fclose(fp);
						return 700000;
					}
			}
		}

		/*	if(IsMoveCamp(i,j)!=1 && IsMoveCamp(i1,j1)==1)  //鐐稿脊鍥炶钀�
		teshu=teshu+2000;
		if(IsMoveCamp(i,j) && cMap[i1][j1]=='0')  //淇濇姢鐐稿脊
		teshu=teshu-2000;*/
		///浣垮繁鏂圭殑妫嬪瓙甯堥暱寰�涓嬩緷娆″湪鐐稿脊鏃�
		for (i2 = 0; i2<12; i2++)  // 鎵惧繁鏂圭偢寮圭殑鏁扮洰
		{
			for (j2 = 0; j2<5; j2++)
				if (cMap[i2][j2] == 'k')
					zha++;
		}
		//mychessdx(cMap,mchess);   //灏嗘垜鏀剧殑妫嬪瓙鐨勬鍔涙寜鐓т粠澶у埌灏忔帓搴�
		int f = 0;
		for (int m = 0; m<25; m++)  //鍒ゆ柇鏁屾柟鍙镐护鍜屽啗闀挎槸鍚︽浜�
		{
			if (dz[m][0] >= 8000 && dz[m][12]>12)
				f++;
			if (dz[m][1] >= 8000 && dz[m][12]>13)
				f++;
		}
		if (zha == 2)
		{
			if (f == 2)//鏁屾柟鍐涢暱鍜屽徃浠ゅ叏閮ㄦ鎺�
				if (Judge(i1, j1, 2, dz) + Judge(i1, j1, 1, dz) + Judge(i1, j1, 0, dz) + Judge(i1, j1, 3, dz) >= 9000)  //鐐稿脊纰板徃浠わ紝鍐涢暱鎴栧笀闀�
					teshu = teshu + 9000;
			if (f == 1 || f == 0)//鏁屾柟鍐涢暱鍜屽徃浠ゆ鎺変竴涓�
				if (Judge(i1, j1, 2, dz) + Judge(i1, j1, 1, dz) + Judge(i1, j1, 0, dz) >= 9000)  //鐐稿脊纰板徃浠わ紝鍐涢暱鎴栧笀闀�
					teshu = teshu + 9000;
		}
		if (zha == 1)
		{
			if (Judge(i1, j1, 1, dz) + Judge(i1, j1, 0, dz) + Judge(i1, j1, 2, dz) >= 9000)  //鐐稿脊纰板徃浠わ紝鍐涢暱鎴栧笀闀�
				teshu = teshu + 9000;
		}
		flag = 0;
		flag1 = 0;
		int k4;
		if (cMap[i1][j1] == '0')
		{
			for (int m = 0; m<12; m++)
			{
				for (int n = 0; n<5; n++)
				{
					if (cMap[m][n] == 'X' && Judge(m, n, 1, dz) + Judge(m, n, 0, dz) + Judge(m, n, 2, dz)<9000)
					{
						k1 = Oppnextmove(m, n, cmap, allmove1);
						for (k2 = 0; k2<k1; k2++)
						{
							if (allmove1[k2][0] == i1 && allmove1[k2][1] == j1)
								flag3 = 1;
						}
					}
				}
			}
			k1 = nextmove1(i1, j1, cmap, allmove1);//鍒ゆ柇宸辨柟妫嬪瓙鑳藉惁纰板ぇ鐨勬瀛�
			for (k2 = 0; k2<k1; k2++)
			{
				if (Judge(allmove1[k2][0], allmove1[k2][1], 1, dz) + Judge(allmove1[k2][0], allmove1[k2][1], 0, dz) + Judge(allmove1[k2][0], allmove1[k2][1], 2, dz) >= 7000)
					flag4 = 1;
			}
			if (flag3 == 0 && flag4 == 1)
				teshu = teshu + 3000;
		}
		flag = 0;
		flag1 = 0;
		for (int m = 0; m<12; m++)
		{
			for (int n = 0; n<5; n++)
			{
				k1 = Oppnextmove(m, n, cMap, allmove1);
				for (k2 = 0; k2<k1; k2++)
				{
					if (allmove1[k2][0] == i && allmove1[k2][1] == j)
						flag = 1;
				}
			}
		}
		for (int m = 0; m<12; m++)
		{
			for (int n = 0; n<5; n++)
			{
				k1 = Oppnextmove(m, n, cmap, allmove1);
				for (k2 = 0; k2<k1; k2++)
				{
					if (allmove1[k2][0] == i1 && allmove1[k2][1] == j1)
						flag1 = 1;
				}
			}
		}
		if (flag == 1 && flag1 == 0)
			teshu = teshu + 1000;
		else
			teshu = teshu - 1000;

	}
	for (i3 = 0; i3<12; i3++)
	{
		for (j3 = 0; j3<5; j3++)
			if (cMap[i3][j3] == 'c')
				x++;
	}
	for (i2 = 0; i2<12; i2++)  // 鎵惧繁鏂圭偢寮圭殑鏁扮洰
	{
		for (j2 = 0; j2<5; j2++)
			if (cMap[i2][j2] == 'k')
				zha++;
	}
	//宸辨柟甯堥暱璺熼殢鍦ㄧ偢寮归檮杩�
	if (cMap[i][j] == 'c' && (x == 2 || x == 1))
	{
		for (i3 = 0; i3<12; i3++)
		{
			for (j3 = 0; j3<5; j3++)
			{
				if (cMap[i3][j3] == 'k')
				{
					k1 = nextmove1(i3, j3, cMap, allmove1);
					for (k2 = 0; k2<k1; k2++)
					{
						if (allmove1[k2][0] == i1 && allmove1[k2][1] == j1)
						{
							if (cMap[i1][j1] == 'X')
								teshu = teshu - 100;
							else if (((j != 0 && j1 == 0) || (j != 4 && j1 == 4)) && cMap[i1][j1] != 'X')
								teshu = teshu + 500;
							else if (((j == 0 && j1 == 0) || (j == 4 && j1 == 4)) && cMap[i1][j1] != 'X')
								teshu = teshu + 1000;
							else
								teshu = teshu + 200;
						}

					}

				}
			}
		}
	}
	if (cMap[i][j] == 'd' && (x == 1 || x == 0))      //鏃呴暱闀�
	{
		for (i3 = 0; i3<12; i3++)
		{
			for (j3 = 0; j3<5; j3++)
			{
				if (cMap[i3][j3] == 'k')
				{
					k1 = nextmove1(i3, j3, cMap, allmove1);
					for (k2 = 0; k2<k1; k2++)
					{
						if (allmove1[k2][0] == i1 && allmove1[k2][1] == j1)
						{
							if (cMap[i1][j1] == 'X')
								teshu = teshu - 100;
							else if (((j != 0 && j1 == 0) || (j != 4 && j1 == 4)) && cMap[i1][j1] != 'X')
								teshu = teshu + 500;
							else if (((j == 0 && j1 == 0) || (j == 4 && j1 == 4)) && cMap[i1][j1] != 'X')
								teshu = teshu + 1000;
							else
								teshu = teshu + 200;
						}
					}

				}
			}
		}
	}
	fprintf(fp, "\n鐐稿脊淇濇姢鍜屼娇鐢ㄥ奖鍝嶇殑鐗规畩鍒� %d ", teshu);
	/************************************************************/
	/************************************************************/
	//琛ュ厖鐐稿脊鐢ㄦ硶:鐐稿脊杩借釜绯荤粺
	if (cMap[i][j] == 'k')
	{
		int xa, ya, difang = 0, zonghe = 0, d, q, u, allmove5[200][2], allmove4[200][2], data = 0, allmove3[200][2];
		int iq, opl1[200][2], im, opk, op = 0, almove[200][2], al, ak, fl1 = 0, ia, ib, fl2 = 0, fl3 = 1, fl4 = 0;
		int pl1 = 0;
		char cmapa[12][5], in, jn, cmap2[12][5];
		for (d = 0; d < 12; d++)
			for (q = 0; q < 5; q++)
			{
				if (cMap[d][q] == 'X'&&Judge(d, q, 2, dz) + Judge(d, q, 1, dz) + Judge(d, q, 0, dz) < 6000)
				{
					u = Oppnextmove(d, q, cMap, allmove5);
				}
			}

		for (xa = 0; xa < 12; xa++)
			for (ya = 0; ya < 5; ya++)
			{
				if (cMap[xa][ya] != '0')
					zonghe++;
				if (cMap[xa][ya] == 'X')
					difang++;
			}

		for (in = 0; in < 12; in++)
			for (jn = 0; jn < 5; jn++)
			{
				cmapa[in][jn] = cMap[in][jn];
			}
		cmapa[i1][j1] = cmapa[i][j];
		cmapa[i][j] = '0';
		if (zonghe > 20)
		{
			if (IsMoveCamp(i, j) != 1 && IsMoveCamp(i1, j1) == 1)
				teshu = teshu + 5000;
			//	if(IsMoveCamp(i,j)!=1 && IsMoveCamp(i1,j1)==1&&allmove5[u][0]==i&&allmove5[u][1]==j)  //鐐稿脊鍥炶钀�
			//		teshu=teshu+6000;
			for (k1 = 0; k1 < 12; k1++)
				for (k2 = 0; k2 < 5; k2++)
					cmap2[k1][k2] = cMap[k1][k2];
			cmap2[i1][j1] = cmap2[i][j];
			cmap2[i][j] = '0';
			k1 = nextmove1(i1, j1, cmap2, allmove3);
			for (k2 = 0; k2 < k1; k2++)
				if ((IsMoveCamp(i1, j1) != 1) && (IsMoveCamp(allmove3[k2][0], allmove3[k2][1]) == 1) && (allmove5[u][0] != allmove3[k2][0]) && (allmove5[u][1] != allmove3[k2][1]))
					teshu = teshu + 3000;
			if (IsMoveCamp(i, j) || (Judge(i1, j1, 2, dz) + Judge(i1, j1, 1, dz) + Judge(i1, j1, 0, dz) < 8000) && cMap[i1][j1] == 'X')  //淇濇姢鐐稿脊
				teshu = teshu - 5000;
			for (iq = 0; iq <= tra - 1; iq++)//涓�姝ヨ拷韪�
				if ((i1 == dz[track[iq]][12]) && (j1 == dz[track[iq]][13]))
				{
					teshu = teshu + 22000;
					fl1 = 1;
					break;
				}
			if (fl1 == 0)  //鏃犳硶涓�姝ヨ拷韪紝杩涜妯℃嫙锛屼袱姝ヨ拷韪�
			{
				al = nextmove1(i1, j1, cmapa, almove); //鎴戞柟绗簩姝ユā鎷�
				for (ia = 0; ia < 12; ia++)
					for (ib = 0; ib < 5; ib++)
						if (cMap[ia][ib] == 'X')
						{
							fl3 = 0;
							for (im = 0; im <= tra - 1; im++)
								if ((ia == dz[track[im]][12]) && (ib == dz[track[im]][13]))
								{
									fl3 = 1;
								}
							if (fl3 == 0)
							{
								op = Oppnextmove(ia, ib, cmapa, opl1); //鏁屾柟涓嬩竴姝ユā鎷�
								for (opk = 0; opk < op; opk++)
								{
									if (opl1[opk][0] == i1 && opl1[opk][1] == j1)   // 鏁屾柟涓嬩竴姝ユ槸鍚﹁兘纰板埌鎴戞柟鐐稿脊绗竴姝�
										fl2 = 1;
								}
							}
						}

				if (fl2 == 0)
				{
					for (ak = 0; ak < al; ak++)
						for (iq = 0; iq <= tra - 1; iq++)//涓�姝ヨ拷韪�
							if ((almove[ak][0] == dz[track[iq]][12]) && (almove[ak][1] == dz[track[iq]][13]))
							{
								teshu = teshu + 9000;
								fl4 = 1;
							}

				}
				//鐐稿脊鍥炶惀
				//****************************************
				//****************************************
				/*if (fl1 == 0 && fl4 == 0)
				{
				if (IsMoveCamp(i, j) != 1 && IsMoveCamp(i1, j1) == 1)  //鐐稿脊涓�姝ュ洖琛岃惀
				{
				teshu = teshu + 3000;
				pl1 = 1;
				}

				if (pl1 == 0&&IsMoveCamp(i, j) != 1)//鐐稿脊妯℃嫙涓ゆ鍥炶惀
				for (in = 0; in < 12; in++)
				for (jn = 0; jn < 5; jn++)
				{
				cmapa[in][jn] = cMap[in][jn];
				}
				cmapa[i1][j1] = cmapa[i][j];
				cmapa[i][j] = '0';
				al = nextmove1(i1, j1, cmapa, almove);
				for (ia = 0; ia < 12; ia++)
				for (ib = 0; ib < 5; ib++)
				if (cMap[ia][ib] == 'X')
				{
				fl3 = 0;
				for (i = 0; i <= tra - 1; i++)
				if ((ia != dz[track[i]][12]) && (ib != dz[track[i]][13]))
				{
				fl3 = 1;
				}
				if (fl3 == 1)
				op = op + Oppnextmove(ia, ib, cmapa, opl1); //鏁屾柟涓嬩竴姝ユā鎷�
				}
				for (opk = 0; opk < op; opk++)
				{
				if (opl1[opk][0] == i1&&opl1[opk][1] == j1)   // 鏁屾柟涓嬩竴姝ユ槸鍚﹁兘纰板埌鎴戞柟鐐稿脊绗竴姝�
				fl2 = 1;
				}
				if (fl2 == 0)
				{
				for (ak = 0; ak < al; ak++)
				if (IsMoveCamp(almove[ak][0], almove[ak][1]) == 1)
				{
				teshu = teshu + 6000;
				}
				}


				}*/

			}
		}
		else
		{
			for (k1 = 0; k1 < 12; k1++)
				for (k2 = 0; k2 < 5; k2++)
					cmap1[k1][k2] = cMap[k1][k2];
			cmap1[i1][j1] = cmap1[i][j];
			cmap1[i][j] = '0';
			if (cMap[i1][j1] == 'X' && (Judge(i1, j1, 2, dz) + Judge(i1, j1, 1, dz) + Judge(i1, j1, 0, dz) + Judge(i1, j1, 3, dz) + Judge(i1, j1, 4, dz) >= 8000))
			{
				data = 1;
				teshu = teshu + 22000;
			}
			else
			{
				/*	if(cMap[i1][j1]=='X'&&(Judge(i1,j1,2,dz)+Judge(i1,j1,1,dz)+Judge(i1,j1,0,dz)<7000))
				teshu=teshu-1000;*/
				if (data == 0)
				{
					k1 = nextmove1(i1, j1, cmap1, allmove4);
					for (k2 = 0; k2 < k1; k2++)
					{
						if (cmap1[allmove4[k2][0]][allmove4[k2][1]] == 'X' && (Judge(allmove4[k2][0], allmove4[k2][1], 3, dz) + Judge(allmove4[k2][0], allmove4[k2][1], 4, dz) + Judge(allmove4[k2][0], allmove4[k2][1], 2, dz) + Judge(allmove4[k2][0], allmove4[k2][1], 1, dz) + Judge(allmove4[k2][0], allmove4[k2][1], 0, dz) >= 8000) && (allmove5[u][0] != i1) && (allmove5[u][1] != j1))
							teshu = teshu + 9000;
						else
						{
							if (IsMoveCamp(i, j) != 1 && IsMoveCamp(i1, j1) == 1)  //鐐稿脊鍥炶钀�
								teshu = teshu + 5000;
							for (k1 = 0; k1 < 12; k1++)
								for (k2 = 0; k2 < 5; k2++)
									cmap2[k1][k2] = cMap[k1][k2];
							cmap2[i1][j1] = cmap2[i][j];
							cmap2[i][j] = '0';
							k1 = nextmove1(i1, j1, cmap2, allmove3);
							for (k2 = 0; k2 < k1; k2++)
								if ((IsMoveCamp(i1, j1) != 1) && (IsMoveCamp(allmove3[k2][0], allmove3[k2][1]) == 1) && (allmove5[u][0] != allmove3[k2][0]) && (allmove5[u][1] != allmove3[k2][1]))
									teshu = teshu + 1000;
							if (IsMoveCamp(i, j) || (Judge(i1, j1, 2, dz) + Judge(i1, j1, 1, dz) + Judge(i1, j1, 0, dz) < 8000) && cMap[i1][j1] == 'X')  //淇濇姢鐐稿脊
								teshu = teshu - 2000;
						}

					}
				}
			}

		}
	}
	fprintf(fp, "\n鐐稿脊杩借釜褰卞搷鍚庣殑鐗规畩鍒嗗�� %d ", teshu);
	/************************************************************/
	/************************************************************/

	//4.宸ュ叺琛屾(淇濇姢涓庢寲闆�)		/////////////////////////////////////////////
	flag = 0;
	flag1 = 0;
	flag3 = 0;
	flag4 = 0;
	sanyi1 = false;
	if (cMap[i][j] == 'i')
	{
		flag = walei(cMap, dz);
		if (flag == 0)
		{
			if (Judge(i1, j1, 9, dz) > 4500)   //宸ュ叺鎸栧湴闆�
			{
				sanyi1 = true;
				teshu = teshu + 4000;
			}
			if (sanyi1 == false && cMap[i1][j1] == '0')
			{
				for (int m = 0; m < 12; m++)
				{
					for (int n = 0; n < 5; n++)
					{
						k1 = Oppnextmove(m, n, cmap, allmove1);
						for (k2 = 0; k2 < k1; k2++)
						{
							if (allmove1[k2][0] == i1 && allmove1[k2][1] == j1)
								flag3 = 1;
						}
					}
				}
				k1 = nextmove1(i1, j1, cmap, allmove1);
				for (k2 = 0; k2 < k1; k2++)
				{
					if (Judge(allmove1[k2][0], allmove1[k2][1], 9, dz) > 4500)
						flag4 = 1;
				}
				if (flag3 == 0 && flag4 == 1)
					teshu = teshu + 2000;
			}
		}
		if (flag == 1)
		{
			if (Judge(i1, j1, 10, dz) >= 4000)   //宸ュ叺纰扮偢寮�
			{
				sanyi1 = true;
				teshu = teshu + 4000;
			}
			if (sanyi1 == false && cMap[i1][j1] == '0')//涓�姝ョ涓嶅埌锛屾ā鎷熶袱姝ョ瀛�
			{
				for (int m = 0; m < 12; m++)
				{
					for (int n = 0; n < 5; n++)
					{
						k1 = Oppnextmove(m, n, cmap, allmove1);
						for (k2 = 0; k2 < k1; k2++)
						{
							if (allmove1[k2][0] == i1 && allmove1[k2][1] == j1)
								flag3 = 1;
						}
					}
				}
				k1 = nextmove1(i1, j1, cmap, allmove1);
				for (k2 = 0; k2 < k1; k2++)
				{
					if (Judge(allmove1[k2][0], allmove1[k2][1], 10, dz) >= 4000)
						flag4 = 1;
				}
				if (flag3 == 0 && flag4 == 1)
					teshu = teshu + 2000;
				if (flag3 == 0)
					teshu = teshu + 2000;
			}
		}
		//宸ュ叺韬查棯鏁屾柟妫嬪瓙
		flag = 0;
		for (int m = 0; m < 12; m++)
		{
			for (int n = 0; n < 5; n++)
			{
				k1 = Oppnextmove(m, n, cMap, allmove1);
				for (k2 = 0; k2 < k1; k2++)
				{
					if (allmove1[k2][0] == i && allmove1[k2][1] == j)
						flag = 1;
				}
			}
		}
		for (int m = 0; m < 12; m++)
		{
			for (int n = 0; n < 5; n++)
			{
				k1 = Oppnextmove(m, n, cmap, allmove1);
				for (k2 = 0; k2 < k1; k2++)
				{
					if (allmove1[k2][0] == i1 && allmove1[k2][1] == j1)
						flag1 = 1;
				}
			}
		}
		if (flag == 1 && flag1 == 0)
			teshu = teshu + 1000;
		else
			teshu = teshu - 1000;
		if (IsMoveCamp(i1, j1))
			teshu = teshu + 300;

		//宸ュ叺鍚庢湡涓诲姩鎸栭浄
		if (NumChess(cMap) < 15 && NumOppChess(cMap) < 15)             //鑷潃寮忔敾鍑�
		{
			/*char cmap10[12][5];
			for (i2 = 0; i2 < 12; i2++)
			for (j2 = 0; j2 < 5; j2++)
			cmap10[i2][j2] == cMap[i2][j2];

			cmap10[i1][j1] = cmap10[i][j];
			cmap10[i][j] = '0';*/
			FILE *fp;
			fp = fopen("1", "a");
			fprintf(fp, "\nwwww");
			fprintf(fp, "\nwwww  %d", Judge(i1, j1, 9, dz));

			int f = 1, f21 = 0, f22 = 0, f23 = 0, f3 = 1;
			fprintf(fp, "\nwwww5  %c %c %c", cMap[9][1], cMap[9][3], mchess[0]);
			if (Judge(i1, j1, 9, dz) > 4000)
				if (cMap[9][1] == mchess[0] || cMap[9][3] == mchess[0])    //鏈�澶х殑鍦ㄥ畧鍐涙棗
				{
					teshu = teshu + 20000;
					f = 0;
					fprintf(fp, "\nwwww1");

				}
			if (cMap[9][1] == mchess[0] || cMap[9][3] == mchess[0])          //鏈�澶х殑鍦ㄥ畧鍐涙棗
				if (f == 1)
				{
					fprintf(fp, "\nwwww22 ");
					k2 = nextmove1(i1, j1, cmap, allmove1);
					fprintf(fp, "\nwwww33 %d ", k2);
					for (k1 = 0; k1 < k2; k1++)
					{
						fprintf(fp, "\nwwww22  %d %d %d", allmove1[k1][0], allmove1[k1][1], Judge(allmove1[k1][0], allmove1[k1][1], 9, dz));
						if (Judge(allmove1[k1][0], allmove1[k1][1], 9, dz) > 4000)
						{
							if (f21 == 0)
							{
								teshu = teshu + 10000;
								f21++;
								f3 = 0;
								fprintf(fp, "\nwww2  %d %d", allmove1[k1][0], allmove1[k1][1]);
							}

						}
					}
				}
			/*if (f3)
			{
			if (cMap[9][1] == mchess[0] || cMap[9][3] == mchess[0])
			{
			for (k1 = 0; k1 < k2; k1++)
			{
			int f31 = 0;
			char cMap3[12][5];
			memcpy(cMap3, cmap, sizeof(cMap3));
			cMap3[allmove1[k1][0]][allmove1[k1][1]] = cMap3[i1][j1];

			k3 = nextmove1(allmove1[k1][0], allmove1[k1][1], cMap3, allmove2);
			for (int k4 = 0; k4 < k3; k4++)
			{
			if (Judge(allmove2[k4][0], allmove2[k4][1], 9, dz)>4000);
			{
			if (f31 == 0)
			{
			teshu += 10000;
			f31++;
			}
			}
			}
			}
			}
			}*/
			fclose(fp);
		}
	}
	sanyi1 = false;
	flag3 = 0;
	flag = 0;
	if (cMap[i][j]>'e' && cMap[i][j]<'i')
	{
		if (Judge(i1, j1, 10, dz) >= 4000)   //灏忕殑妫嬪瓙纰扮偢寮�
		{
			sanyi1 = true;
			teshu = teshu + 4000;
		}
		if (sanyi1 == false && cMap[i1][j1] == '0')//涓�姝ョ涓嶅埌锛屾ā鎷熶袱姝ョ瀛�
		{
			/*	for(int m=0;m<12;m++)
			{
			for(int n=0;n<5;n++)
			{
			if(weixie(i,j,m,n,dz,cMap)<0)
			{
			k1=Oppnextmove(m,n,cmap,allmove1);
			for(k2=0;k2<k1;k2++)
			{
			if(allmove1[k2][0]==i1 && allmove1[k2][1]==j1)
			flag3=1;
			}
			}
			}
			}*/
			k1 = nextmove1(i1, j1, cmap, allmove1);
			for (k2 = 0; k2<k1; k2++)
			{
				if (Judge(allmove1[k2][0], allmove1[k2][1], 10, dz) >= 4000)
					flag = 1;
			}
		}
		if (flag3 == 0 && flag == 1)
			teshu = teshu + 1500;
	}
	if (i >= 10)
		teshu = teshu - 300;
	if (cMap[11][0] == 'h'&&Judge(10, 0, 8, dz) > 8000)
		if (i == 11 && j == 0 && i1 == 10 && j1 == 0)
			teshu = teshu + 50000;
	if (cMap[11][2] == 'h'&&Judge(10, 2, 8, dz) > 8000)
		if (i == 11 && j == 2 && i1 == 10 && j1 == 2)
			teshu = teshu + 50000;
	fprintf(fp, "\n宸ュ叺鐨勭敤娉曞奖鍝嶅悗鐨勭壒娈婂垎鍊� %d ", teshu);
	fprintf(fp, "\n鎴戞柟鍙Щ鍔ㄦ瀛愭暟 %d", MyMovingChess(cMap));

	/*if (MyMovingChess(cMap) == 1)
	{
	if (cMap[11][1] == 'l')
	{
	fprintf(fp, "\nsss1 ");
	if (i1 = 10 && j1 == 1)
	{
	teshu = teshu + 2000;
	fprintf(fp, "\nsss2 ");
	}
	}
	if (cMap[11][3] == 'l')
	{
	fprintf(fp, "\nsss3 ");
	if (i1 = 10 && j1 == 3)
	{
	teshu = teshu + 2000;
	fprintf(fp, "\nsss4 ");
	}
	}
	}*/
	/*if (cMap[i1][j1] == '0')
	teshu = teshu + 2000;*/
	fprintf(fp, "\n鍚屼笂锛燂紵 %d ", teshu);
	fclose(fp);
	weixief = weixie(i, j, i1, j1, dz, cMap) / 10;            /////   鏀逛负鍜岄棿鎺ュ▉鑳佺浉鍚�/  //weixief=weixie(i,j,i1,j1,dz,cMap)/5;
	qipan = qipanfen[i1][j1] - qipanfen[i][j];
	jweixief = jweixie(i1, j1, dz, cmap) / 10;
	score = weixief + qipan + jweixief + sanyif + teshu;
	score += DefendFlag(cMap, i, j, i1, j1);
	score += DefendLeft(i, j, i1, j1, cMap);
	score += DefendRight(i, j, i1, j1, cMap);
	score += AttackFor31(cMap, i, j, i1, j1);
	fp = fopen("1", "a");
	fprintf(fp, "\n%s,%d,%s,%d,%s,%d,%s,%d,%s,%d\n%c %d,%d,%d,%d\n", "鐩存帴濞佽儊", weixief, "闂存帴濞佽儊", jweixief, "涓夊崄涓�姝ュ垎鍊�", sanyif, "鐗规畩鍒�", teshu, "鎬诲垎", score, cMap[i][j], i, j, i1, j1);
	fclose(fp);

	/*if (Ina_step[0] == 2 && Ina_step[1]>12)
	return score1;
	else*/
	return score;
}
void CulBestmove(char cMap[12][5], char *cInMessage, char *cOutMessage, int dz[25][14])																	//cInMessage琚幓闄ゆ帀锛屾病浠�涔堜綔鐢�
{
	strcpy(cOutMessage, "BESTMOVE A0A0");
	int move[4];
	int allmove[200][4], iSaMove[40][2];
	int i, j, num, num1, i1, j1, k = 0;
	char cmap[12][5];
	int score1, score = -10000;
	//瀹氬紡
	if (1)
	{
		//鎴戞柟瀛愬湪鏁屾柟鍐涙棗鏃佽竟
		if (cMap[0][1] == 'L')
		{
			if (IsMyMovingChess(cMap, 0, 0))
			{
				cOutMessage[9] = 'A';
				cOutMessage[10] = '0';
				cOutMessage[11] = 'A';
				cOutMessage[12] = '1';
				return;
			}
			if (IsMyMovingChess(cMap, 0, 2))
			{
				cOutMessage[9] = 'A';
				cOutMessage[10] = '2';
				cOutMessage[11] = 'A';
				cOutMessage[12] = '1';
				return;
			}
			if (IsMyMovingChess(cMap, 1, 1))
			{
				cOutMessage[9] = 'B';
				cOutMessage[10] = '1';
				cOutMessage[11] = 'A';
				cOutMessage[12] = '1';
				return;
			}
		}
		if (cMap[0][3] == 'L')
		{
			if (IsMyMovingChess(cMap, 0, 4))
			{
				cOutMessage[9] = 'A';
				cOutMessage[10] = '4';
				cOutMessage[11] = 'A';
				cOutMessage[12] = '3';
				return;
			}
			if (IsMyMovingChess(cMap, 0, 2))
			{
				cOutMessage[9] = 'A';
				cOutMessage[10] = '2';
				cOutMessage[11] = 'A';
				cOutMessage[12] = '3';
				return;
			}
			if (IsMyMovingChess(cMap, 1, 3))
			{
				cOutMessage[9] = 'B';
				cOutMessage[10] = '3';
				cOutMessage[11] = 'A';
				cOutMessage[12] = '3';
				return;
			}
		}

		if (cMap[0][0] >= 'e' && cMap[0][0]<'j' && !IsMyChess(cMap, 0, 1))
		{
			cOutMessage[9] = 'A';
			cOutMessage[10] = '0';
			cOutMessage[11] = 'A';
			cOutMessage[12] = '1';
			return;
		}
		if (cMap[0][2] >= 'e' && cMap[0][2]<'j' && !IsMyChess(cMap, 0, 1))
		{
			cOutMessage[9] = 'A';
			cOutMessage[10] = '2';
			cOutMessage[11] = 'A';
			cOutMessage[12] = '1';
			return;
		}
		if (cMap[1][1] >= 'e' && cMap[1][1]<'j' && !IsMyChess(cMap, 0, 1))
		{
			cOutMessage[9] = 'B';
			cOutMessage[10] = '1';
			cOutMessage[11] = 'A';
			cOutMessage[12] = '1';
			return;
		}

		if (cMap[0][4] >= 'e' && cMap[0][4]<'j' && !IsMyChess(cMap, 0, 3))
		{
			cOutMessage[9] = 'A';
			cOutMessage[10] = '4';
			cOutMessage[11] = 'A';
			cOutMessage[12] = '3';
			return;
		}
		if (cMap[0][2] >= 'e' && cMap[0][2]<'j' && !IsMyChess(cMap, 0, 3))
		{
			cOutMessage[9] = 'A';
			cOutMessage[10] = '2';
			cOutMessage[11] = 'A';
			cOutMessage[12] = '3';
			return;
		}
		if (cMap[1][3] >= 'e' && cMap[1][3]<'j' && !IsMyChess(cMap, 0, 3))
		{
			cOutMessage[9] = 'B';
			cOutMessage[10] = '3';
			cOutMessage[11] = 'A';
			cOutMessage[12] = '3';
			return;
		}
	}
	FILE *fp;
	fp = fopen("1", "a");
	for (int m = 0; m<12; m++)
	{
		for (int n = 0; n<5; n++)
		{
			fprintf(fp, "%c ", cMap[m][n]);
		}
		fprintf(fp, "\n");
	}
	fprintf(fp, "\n\n\n%d,%d\n", Ina_step[0], Ina_step[1]);
	for (i = 0; i<25; i++)
	{
		for (j = 0; j<14; j++)
			fprintf(fp, "%5d,", dz[i][j]);
		fprintf(fp, "\n");
	}
	fclose(fp);

	for (i = 0; i<12; i++)
		for (j = 0; j<5; j++)
		{
			if (IsMyMovingChess(cMap, i, j) && !IsBaseCamp(i, j))  //宸辨柟涓嶅湪澶ф湰钀ョ殑鍙Щ鍔ㄦ瀛�
			{
				//宸ュ叺褰㈡
				if (cMap[i][j] == 'i' && IsRailway(i, j))
				{
					iSaMove[0][0] = i;
					iSaMove[0][1] = j;
					for (i1 = 0; i1<12; i1++)
					{
						for (j1 = 0; j1<5; j1++)
							cmap[i1][j1] = cMap[i1][j1];
					}
					num = SapperRail(iSaMove, cmap, i, j, 0);
					for (num1 = 1; num1<num; num1++)
					{
						allmove[k][0] = i;
						allmove[k][1] = j;
						allmove[k][2] = iSaMove[num1][0];
						allmove[k][3] = iSaMove[num1][1];
						k++;
					}
				}
				//鍙互鍓嶇Щ:涓嶅湪绗竴琛�,涓嶅湪灞辩晫鍚�,鍓嶆柟涓嶆槸宸辨柟妫嬪瓙,鍓嶆柟涓嶆槸鏈夋瀛愬崰棰嗙殑琛岃惀
				if (i>0 && !IsAfterHill(i, j) && !IsMyChess(cMap, i - 1, j) && !IsFilledCamp(cMap, i - 1, j))
				{
					allmove[k][0] = i;
					allmove[k][1] = j;
					allmove[k][2] = i - 1;
					allmove[k][3] = j;
					k++;
					if ((j == 0 || j == 4) && i>0 && i<11)
					{
						for (i1 = i - 1; i1>0; i1--)
						{
							if (cMap[i1][j] == '0')
							{
								allmove[k][0] = i;
								allmove[k][1] = j;
								allmove[k][2] = i1;
								allmove[k][3] = j;
								k++;
							}
							else if (cMap[i1][j] >= 'A' && cMap[i1][j] == 'X')
							{
								allmove[k][0] = i;
								allmove[k][1] = j;
								allmove[k][2] = i1;
								allmove[k][3] = j;
								k++;
								break;
							}
							else break;
						}
					}
				}
				//鍙互宸︾Щ:涓嶅湪鏈�宸﹀垪,宸︿晶涓嶆槸宸辨柟妫嬪瓙,宸︿晶涓嶆槸琚崰鐢ㄧ殑琛岃惀
				if (j>0 && !IsMyChess(cMap, i, j - 1) && !IsFilledCamp(cMap, i, j - 1))
				{
					allmove[k][0] = i;
					allmove[k][1] = j;
					allmove[k][2] = i;
					allmove[k][3] = j - 1;
					k++;
					//鏄惁鍦�1,5,6,10閾侀亾涓�
					if (i == 1 || i == 5 || i == 6 || i == 10)
					{
						for (int i1 = j - 1; i1 >= 0; i1--)
						{
							if (cMap[i][i1] == '0')
							{
								allmove[k][0] = i;
								allmove[k][1] = j;
								allmove[k][2] = i;
								allmove[k][3] = i1;
								k++;
							}
							else if (cMap[i][i1] >= 'A'&&cMap[i][i1] <= 'X')
							{
								allmove[k][0] = i;
								allmove[k][1] = j;
								allmove[k][2] = i;
								allmove[k][3] = i1;
								k++;
								break;
							}
							else break;
						}
					}
				}
				//鍙互鍙崇Щ:涓嶅湪鏈�鍙冲垪,鍙充晶涓嶆槸宸辨柟妫嬪瓙,鍙充晶涓嶆槸琚崰鐢ㄧ殑琛岃惀
				if (j<4 && !IsMyChess(cMap, i, j + 1) && !IsFilledCamp(cMap, i, j + 1))
				{
					allmove[k][0] = i;
					allmove[k][1] = j;
					allmove[k][2] = i;
					allmove[k][3] = j + 1;
					k++;
					//鏄惁鍦�1,5,6,10閾侀亾涓�
					if (i == 1 || i == 5 || i == 6 || i == 10)
					{
						for (int i1 = j + 1; i1<5; i1++)
						{
							if (cMap[i][i1] == '0')
							{
								allmove[k][0] = i;
								allmove[k][1] = j;
								allmove[k][2] = i;
								allmove[k][3] = i1;
								k++;
							}
							else if (cMap[i][i1] >= 'A'&&cMap[i][i1] <= 'X')
							{
								allmove[k][0] = i;
								allmove[k][1] = j;
								allmove[k][2] = i;
								allmove[k][3] = i1;
								k++;
								break;
							}
							else break;
						}
					}
				}

				//鍙互鍚庣Щ锛氫笉鍦ㄦ渶鍚庝竴鍒楋紝鍚庢柟涓嶆槸宸辨柟鏃楀瓙锛屽悗闈笉鏄凡鍗犳湁鐨勮钀�
				if (i<11 && !IsBehindHill(i, j) && !IsMyChess(cMap, i + 1, j) && !IsFilledCamp(cMap, i + 1, j))
				{
					allmove[k][0] = i;
					allmove[k][1] = j;
					allmove[k][2] = i + 1;
					allmove[k][3] = j;
					k++;
					//鍙互鍦ㄩ搧杞ㄤ袱渚у悜鍚庣Щ鍔紝鍚庢柟涓嶆槸宸辨柟鏃楀瓙锛屼笉鏄涓�琛岋紝涓嶅湪鏈�鍚庝竴琛�
					if ((j == 0 || j == 4) && i>0 && i<11)
					{
						for (i1 = i + 1; i1<11; i1++)
						{
							if (cMap[i1][j] == '0')
							{
								allmove[k][0] = i;
								allmove[k][1] = j;
								allmove[k][2] = i1;
								allmove[k][3] = j;
								k++;
							}
							else if (cMap[i1][j] >= 'A' && cMap[i1][j] <= 'X')
							{
								allmove[k][0] = i;
								allmove[k][1] = j;
								allmove[k][2] = i1;
								allmove[k][3] = j;
								k++;
								break;
							}
							else  break;
						}

					}
				}
				//鍙互宸﹀墠绉伙細宸﹀墠鏂逛笉鏄凡鍗犳湁鐨勮钀ワ紝涓嶆槸宸辨柟鏃楀瓙
				if ((Iszuoqian(i, j) || IsMoveCamp(i, j)) && !IsMyChess(cMap, i - 1, j - 1) && !IsFilledCamp(cMap, i - 1, j - 1))
				{
					allmove[k][0] = i;
					allmove[k][1] = j;
					allmove[k][2] = i - 1;
					allmove[k][3] = j - 1;
					k++;
				}
				//鍙互宸﹀悗绉伙細宸﹀悗鏂逛笉鏄繁鏂规棗瀛愶紝涓嶆槸宸插崰鏈夌殑琛岃惀
				if ((Iszuohou(i, j) || IsMoveCamp(i, j)) && !IsMyChess(cMap, i + 1, j - 1) && !IsFilledCamp(cMap, i + 1, j - 1))
				{
					allmove[k][0] = i;
					allmove[k][1] = j;
					allmove[k][2] = i + 1;
					allmove[k][3] = j - 1;
					k++;
				}
				//鍙互鍙冲墠绉伙細鍙冲墠鏂逛笉鏄繁鏂规棗瀛愶紝涓嶆槸宸插崰鏈夌殑琛岃惀
				if ((Isyouqian(i, j) || IsMoveCamp(i, j)) && !IsMyChess(cMap, i - 1, j + 1) && !IsFilledCamp(cMap, i - 1, j + 1))
				{
					allmove[k][0] = i;
					allmove[k][1] = j;
					allmove[k][2] = i - 1;
					allmove[k][3] = j + 1;
					k++;
				}
				//鍙互鍙冲悗绉伙細鍙冲悗鏂逛笉鏄繁鏂规棗瀛愶紝涓嶆槸宸插崰鏈夌殑琛岃惀
				if ((Isyouhou(i, j) || IsMoveCamp(i, j)) && !IsMyChess(cMap, i + 1, j + 1) && !IsFilledCamp(cMap, i + 1, j + 1))
				{
					allmove[k][0] = i;
					allmove[k][1] = j;
					allmove[k][2] = i + 1;
					allmove[k][3] = j + 1;
					k++;
				}
			}
		}
	for (i = 0; i<k; i++)
	{
		if ((score1 = pinggu(allmove[i][0], allmove[i][1], allmove[i][2], allmove[i][3], dz, cMap)) >= score)
		{
			if (allmove[i][0] == allmove[i][2] && allmove[i][1] == allmove[i][3])
				continue;
			else
			{
				score = score1;
				move[0] = allmove[i][0];
				move[1] = allmove[i][1];
				move[2] = allmove[i][2];
				move[3] = allmove[i][3];
			}
		}
	}
	cOutMessage[9] = move[0] + 'A';
	cOutMessage[10] = move[1] + '0';
	cOutMessage[11] = move[2] + 'A';
	cOutMessage[12] = move[3] + '0';
	fp = fopen("1", "a");
	qqqqqq++;
	fprintf(fp, "\n绗�%d姝ョ粨鏉�%d,%d,%d,%d,%d,%d\n", qqqqqq, move[0], move[1], move[2], move[3], score1, score);
	//	fprintf(fp,"\n%d\n",zz++);
	fclose(fp);
}
/* ************************************************************************ */
/* 鍑芥暟鍔熻兘锛氳绠楀繁鏂规渶浣崇潃娉�(鏈▼搴忎负绀轰緥绠楁硶,璇峰弬璧涢�夋墜鑷鏀硅繘绠楁硶)		*/
/* 鎺ュ彛鍙傛暟锛�																*/
/*     char *cMap 妫嬬洏灞�闈�													*/
/*     char *cInMessage 鏉ヨ嚜瑁佸垽鐨� GO 鍛戒护									*/
/*     char *cOutMessage 鍙戠粰瑁佸垽鐨� BESTMOVE 鍛戒护							*/
/* ************************************************************************ */


int main()
{
	char cVer[200];			//鍗忚鐗堟湰
	int iFirst;				//鍏堣鏉僛0鍏堣锛�1鍚庤]																							//涓嶇煡閬搃First銆乮Time銆乮Step鏈変粈涔堢敤锛熷彲鑳戒笌骞冲彴鏈夊叧绯汇��
	int iTime;				//琛屾鏃堕棿闄愬埗(鍗曚綅绉�)[1000,3600]
	int iStep;				//杩涙敾绛夊緟闄愬埗(鍗曚綅姝�)[10,31]
	char cInMessage[200];   //杈撳叆閫氫俊鍐呭
	char cOutMessage[200];  //杈撳嚭閫氫俊鍐呭
	char cIn1[200], cIn2[200];
	char cMap[12][5];		//妫嬬洏
							//   鍙镐护 ,鍐涢暱 ,甯堥暱 ,鏃呴暱 ,鍥㈤暱 ,钀ラ暱 ,杩為暱 ,鎺掗暱 ,宸ュ叺 ,鍦伴浄 ,鐐稿脊 ,鍐涙棗     i,j,(璇ュ瓙鎵�鍦ㄤ綅缃�)
	int dz[25][14] = {
		100  ,100  ,250  ,500  ,500  ,700  ,2000 ,2100 ,400  ,3250 ,100  ,0    ,   0,0,//A0  10000
		0    ,0    ,0    ,0    ,0    ,0    ,0    ,3000 ,0    ,2000 ,0    ,5000 ,   0,1,//A1
		100  ,100  ,250  ,500  ,500  ,700  ,2000 ,2100 ,200  ,3250 ,100  ,0    ,   0,2,//A2
		0    ,0    ,0    ,0    ,0    ,0    ,0    ,3000 ,0    ,2000 ,0    ,5000 ,   0,3,//A3
		100  ,100  ,250  ,500  ,500  ,700  ,2000 ,2100 ,400  ,3250 ,100  ,0    ,   0,4,//A4

		500  ,500  ,850  ,700  ,600  ,500  ,600  ,500  ,1000 ,3250 ,1000 ,0    ,   1,0,//B0
		400  ,400  ,850  ,700  ,600  ,500  ,800  ,600  ,1000 ,3250 ,900  ,0    ,   1,1,//B1
		400  ,400  ,850  ,700  ,600  ,500  ,800  ,600  ,1000 ,3250 ,900  ,0    ,   1,2,//B2
		400  ,400  ,850  ,700  ,600  ,500  ,800  ,600  ,1000 ,3250 ,900  ,0    ,   1,3,//B3
		500  ,500  ,850  ,700  ,600  ,500  ,600  ,500  ,1000 ,3250 ,1000 ,0    ,   1,4,//B4

		500  ,500  ,1000 ,1000 ,1000 ,1500 ,500  ,500  ,2000 ,0    ,1500 ,0    ,   2,0,//C0
		500  ,500  ,1000 ,1000 ,1000 ,1500 ,500  ,500  ,2000 ,0    ,1500 ,0    ,   2,2,//C2
		500  ,500  ,1000 ,1000 ,1000 ,1500 ,500  ,500  ,2000 ,0    ,1500 ,0    ,   2,4,//C4

		500  ,500  ,1000 ,1000 ,1000 ,1500 ,500  ,500  ,2000 ,0    ,1500 ,0    ,   3,0,//D0
		500  ,500  ,1000 ,1000 ,1000 ,1500 ,500  ,500  ,2000 ,0    ,1500 ,0    ,   3,1,//D1
		500  ,500  ,1000 ,1000 ,1000 ,1500 ,500  ,500  ,2000 ,0    ,1500 ,0    ,   3,3,//D3
		500  ,500  ,1000 ,1000 ,1000 ,1500 ,500  ,500  ,2000 ,0    ,1500 ,0    ,   3,4,//D4

		500  ,500  ,1000 ,1000 ,1000 ,1500 ,500  ,500  ,2000 ,0    ,1500 ,0    ,   4,0,//E0
		500  ,500  ,1000 ,1000 ,1000 ,1500 ,500  ,500  ,2000 ,0    ,1500 ,0    ,   4,2,//E2
		500  ,500  ,1000 ,1000 ,1000 ,1500 ,500  ,500  ,2000 ,0    ,1500 ,0    ,   4,4,//E4

		500  ,500  ,1000 ,1000 ,1200 ,2800 ,1500 ,1500 ,0    ,0    ,0    ,0    ,   5,0,//F0
		500  ,500  ,1000 ,1000 ,1000 ,1000 ,1500 ,1500 ,2000 ,0    ,0    ,0    ,   5,1,//F1
		500  ,500  ,1000 ,1000 ,1100 ,2800 ,1600 ,1500 ,0    ,0    ,0    ,0    ,   5,2,//F2
		500  ,500  ,1000 ,1000 ,1000 ,1000 ,1500 ,1500 ,2000 ,0    ,0    ,0    ,   5,3,//F3
		500  ,500  ,1000 ,1000 ,1200 ,2800 ,1500 ,1500 ,0    ,0    ,0    ,0    ,   5,4,//F4
	};   //鐚滄祴姒傜巼                  10000     22200  27600



		 //cin.gets(a,20)		gets(a)		cin.get(str,size).get();鍚庨潰鐨刧et()鐢ㄤ簬娓呴櫎鍓嶉潰杈撳叆鐨勬畫鐣欏湪缂撳啿鍖虹殑鎹㈣绗︺��
	cin.getline(cInMessage, 200);		//鑾峰彇鏉ヨ嚜瑁佸垽绯荤粺鐨勬寚浠� "GO 0000 0 00"
										//	gets(cInMessage);

	while (cInMessage[0] >= 'A')
	{
		if (strcmp(cIn1, cIn2) == 0) {
			//		printf("han been gone run!\n");
		}
		else {
			//		FILE *fp;
			//		fp=fopen("D:/Debug/ceshi.txt","a");
			//	fprintf(fp,"%s%s\n","鍙戦�佹寚浠�:",cInMessage);
			switch (cInMessage[0])
			{

			case 'I':								//INFO鎸囦护
				CulInfo(cInMessage, cVer, cOutMessage);
				cout << cOutMessage << endl;			//灏�"NAME "鎸囦护浼犻�掔粰瑁佸垽绯荤粺
				break;
			case 'S':								//START 鎸囦护
				CulArray(cInMessage, &iFirst, &iTime, &iStep, cOutMessage);
				InitMap(cMap, cOutMessage);
				cout << cOutMessage << endl;
				break;
			case 'G':								//GO 鎸囦护
				FreshMap(cMap, cInMessage, cOutMessage, dz);
				CulBestmove(cMap, cInMessage, cOutMessage, dz);
				cout << cOutMessage << endl;
				break;
			case 'R':								//RESULT 鎸囦护
				FreshMap(cMap, cInMessage, cOutMessage, dz);
				//	cout<<cOutMessage<<endl;
				break;
			case 'E':								//END 鎸囦护
				return 0;
			default:
				return 1;

			}
			//		fprintf(fp,"%s%s\n","鎺ュ彈鎸囦护:",cOutMessage);
			//	fclose(fp);
		}
		strcpy(cIn1, cInMessage);
		//	cin.getline(cInMessage,200);	//鑾峰彇鏉ヨ嚜瑁佸垽绯荤粺鐨勬寚浠�"START" 鎴� "RESULT" 鎴� "GO" 鎴� "END"

		while (1) {
			gets_s(cInMessage);
			if (cInMessage[0] >= 'A') {
				break;
			}
		}
		strcpy(cIn2, cInMessage);
	}
	return 0;
}
