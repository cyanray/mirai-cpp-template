// 注意: 本项目的所有源文件都必须是 UTF-8 编码

// 这是一个“反撤回”机器人
// 在群里回复 “/anti-recall enabled.” 或者 “撤回没用” 之后
// 如果有人在群里撤回，那么机器人会把撤回的内容再发出来

#include <iostream>
#include <map>
#include <mirai.h>
#include "myheader.h"

int main()
{
	using namespace std;
	using namespace Cyan;

#if defined(WIN32) || defined(_WIN32)
	// 切换代码页，让 CMD 可以显示 UTF-8 字符
	system("chcp 65001");
#endif

	MiraiBot bot("127.0.0.1", 8080);
	while (true)
	{
		try
		{
			bot.Auth("InitKeyVl0CEUzZ", 211000000_qq);
			break;
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
		}
		MiraiBot::SleepSeconds(1);
	}
	cout << "Bot Working..." << endl;

	map<GID_t, bool> groups;

	bot.On<GroupMessage>(
		[&](GroupMessage m)
		{
			try
			{
				string plain = m.MessageChain.GetPlainText();
				if (plain == "/anti-recall enabled." || plain == "撤回没用")
				{
					groups[m.Sender.Group.GID] = true;
					m.Reply(MessageChain().Plain("撤回也没用，我都看到了"));
					return;
				}
				if (plain == "/anti-recall disabled." || plain == "撤回有用")
				{
					groups[m.Sender.Group.GID] = false;
					m.Reply(MessageChain().Plain("撤回有用"));
					return;
				}
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
		});


	bot.On<GroupRecallEvent>(
		[&](GroupRecallEvent gm)
		{
			try
			{
				if (!groups[gm.Group.GID]) return;
				auto recalled_mc = bot.GetGroupMessageFromId(gm.MessageId).MessageChain;
				auto mc = "刚刚有人撤回了: " + recalled_mc;
				bot.SendMessage(gm.Group.GID, mc);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
		});


	bot.EventLoop();

	return 0;
}