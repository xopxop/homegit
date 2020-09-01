#include <ncurses.h>
#include <string>

int main(int argc, char **argv)
{
	initscr();
	cbreak();
	noecho();
	clear();
	refresh();

	move (5,5);
	std::string text = "Hello world!";
	for (int i = 0; i < text.size(); i++)
	{
		addch(text[i]);
		addch(' ');
	}
	while(1);
	return 0;
}