
#include "glew.h"
#include "filesystem"
#include <map>
class Image;
class Color4ub;

enum class Textures
{
	STARTCUT1, STARTCUT2, STARTCUT3,SKIP, nextd,
	BAR1, QUITCHECK, YES, NO_P, YES_P, no, background1,playUI, 
	playUI_2, quitUI, quitUI_2, optionUI, optionUI_2, restartUI, restartUI_2, linePuzzle, blackPuzzle,curvePuzzle,
	imageStart, imageEnd, image01, curve2Puzzle, levelButton, levelButton_2,
	character, clear, level, num1,num2, failScreen, next
	,yellow, background2,mini, threePuzzle, vPuzzle, movePuzzle, 
	num0, num3,num4, num5, num6, num7, num8, num9, VPuzzle2, leftTurn , lineEnd, lineStart, autoLine, autoV, autoCurve, qutoEnd, yellowPuzzle, clickLeft, clickRight, clickPlayButton, clickPlayButton2,
	level1, leve1p, level2, level2p, level3,level3p,level4,level4p,level5,level5p,level6,level6p,level7,level7p,level8,level8p,level9,level9p,level10,level10p,level11,level11p, levelLock,
	fullCheck, fullCheck2, volumeL, volumeR, quitL, quitLp, optionL, musicL, bar0, fullScrenL,
	resume,resume2, backtomain, backtomain2,
	background3,
	credit,creatP, optionLP, start, startP, tutorial, tutorialP , title,
	controls,
	credit1,credit2,credit3,
	controlButton, controlButtonP, back, ending1, ending2
};

class Texture
{
public:
	Texture();

	void CreateTexture(char const* filename,Textures typeOfTexture);
	void DeleteTexture() noexcept;
	GLuint CreateTexture(char const* filename, int i);
	GLuint GetTexture(Textures typeOfTexture) {
		return TextureStore[typeOfTexture];
	}
	void Load1();
	void Load2();
	void Load3();
	void Load4();

	unsigned int GetTextureHandle() const noexcept { return textureHandle; }
	int          GetWidth() const noexcept { return width; }
	int          GetHeight() const noexcept { return height; }

	~Texture() noexcept;
	Texture(Texture&& other) noexcept;
	Texture& operator=(Texture&& other) noexcept;

public:
	Texture(const Texture& other) = delete;
	Texture& operator=(const Texture& other) = delete;

private:
	unsigned int textureHandle = 0;
	int          width = 0;
	int          height = 0;
	std::map<Textures,GLuint> TextureStore;
};
extern Texture* TEXTURE;