#include"main.h"
int main()
{
	char c;
	c_comi();
	while (true)
	{
		/*cout << "选择一个功能" << endl;
		cout << "按下r 颜色识别红色" << endl;
		cout << "按下y 颜色识别黄色" << endl;
		cout << "按下b 颜色识别蓝色" << endl;
		cout << "按下f 图形匹配芬达" << endl;
		cout << "按下k 图形匹配可乐" << endl;
		cout << "按下x 图形匹配雪碧" << endl;
		cout << "按下e 退出" << endl;*/
		c = c_comr();

		if (c == 'r'||c == 'y'||c == 'b')
		{
			cout << "颜色识别" << endl;
			check_color(c);
			cout << "success" << endl;
		}
		else if (c == 'f'||c == 'k'||c == 'x'||c == '1')
		{
			cout << "图形匹配" << endl;
			check_shape('f');
			cout << "suceess" << endl;
		}
		else if (c == 'e')
		{
			cout << "退出" << endl;
			return 0;
		}
		else
			cout << "失败" << endl;
	}
}