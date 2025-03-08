#include <iostream>
#include <ctime>

int	main(void)
{
	std::time_t	now = std::time(NULL); //Unix時間(1970年1月1日00:00)から現在までの経過秒数を取得
	std::tm*	localtime = std::localtime(&now); //Unix時間を年・月・日・時・分・秒に変換したstd::tm構造体を返します
	char	buf[18]; //文字列を格納するバッファ

	std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%I%S]", localtime); //日時/時刻をstring型に変換する
	std::cout << buf;
	return (0);
}
