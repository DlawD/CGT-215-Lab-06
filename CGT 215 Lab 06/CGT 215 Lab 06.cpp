#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main() {

	string background = "images1/backgrounds/winter.png";
	string foreground = "images1/characters/yoda.png";
	Texture backgroundTex;
	Texture foregroundTex;

	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	
	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();
	Image foregroundImage;
	foregroundImage = foregroundTex.copyToImage();
	Vector2u sz = backgroundImage.getSize();

	Color findgreen = foregroundImage.getPixel(1, 1);
	for (int y = 0; y < sz.y; y++) {
		for (int x = 0; x < sz.x; x++) {
			if (foregroundImage.getPixel(x, y) == findgreen) {
				foregroundImage.setPixel(x, y, backgroundImage.getPixel(x, y));
			}
		}
	}

	Texture tex1;
	tex1.loadFromImage(foregroundImage);

	RenderWindow window(VideoMode(1024, 768), "Here's the output");
	Sprite sprite1;
	sprite1.setTexture(tex1);
	window.clear();
	window.draw(sprite1);
	window.display();
	while (true);

}