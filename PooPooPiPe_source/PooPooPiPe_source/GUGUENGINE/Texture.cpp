
#include <cassert>
#include <filesystem>
#include "Image.h"
#include "Texture.h"
#include "glew.h"
#include "glCheck.h"
#include <iostream>
#include "Mesh.h"
#include "external/stb/include/stb_image.h"

Texture* TEXTURE = nullptr;
Texture::Texture()
{
    TEXTURE = this;
}

Texture::Texture(Texture&& other) noexcept
    : textureHandle{ other.textureHandle }, width{ other.width }, height{ other.height }
{
    other.textureHandle = 0;
    other.width = 0;
    other.height = 0;
}

void Texture::CreateTexture(char const* filename, Textures typeOfTexture)
{
    GLuint texture;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    int mwidth, mheight, mnrChannels;
    unsigned char* data = stbi_load(filename, &mwidth, &mheight, &mnrChannels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mwidth, mheight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    glBindTexture(GL_TEXTURE_2D, static_cast<GLuint>( TextureStore.size()));

    stbi_image_free(data);

    TextureStore[typeOfTexture] = texture;
}

GLuint Texture::CreateTexture(char const* filename, int i)
{
    GLuint texture;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    int mwidth, mheight, mnrChannels;
    unsigned char* data = stbi_load(filename, &mwidth, &mheight, &mnrChannels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mwidth, mheight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    glBindTexture(GL_TEXTURE_2D, i);

    stbi_image_free(data);

    return texture;
    //TextureStore.push_back(texture);
}

void Texture::Load1()
{
    TextureStore.clear();
    CreateTexture("assets\\imagest1.png", Textures::STARTCUT1);
    CreateTexture("assets\\imagest2.png", Textures::STARTCUT2);
    CreateTexture("assets\\imagest3.png", Textures::STARTCUT3);
    CreateTexture("assets\\skip.png", Textures::SKIP);
    CreateTexture("assets\\nextd.png", Textures::nextd);
    CreateTexture("assets\\bar1.png", Textures::BAR1);
    CreateTexture("assets\\quitcheck.png", Textures::QUITCHECK);
    CreateTexture("assets\\yes.png", Textures::YES);
    CreateTexture("assets\\no_p.png", Textures::NO_P);
    CreateTexture("assets\\yes_p.png", Textures::YES_P);
    CreateTexture("assets\\no.png", Textures::no);
    CreateTexture("assets\\background1.png", Textures::background1);

}
void Texture::Load2()
{
    CreateTexture("assets\\playUI.png", Textures::playUI);
    CreateTexture("assets\\playUI_2.png", Textures::playUI_2);
    CreateTexture("assets\\quitUI.png", Textures::quitUI);
    CreateTexture("assets\\quitUI_2.png", Textures::quitUI_2);
    CreateTexture("assets\\optionUI.png", Textures::optionUI);
    CreateTexture("assets\\optionUI_2.png", Textures::optionUI_2);
    CreateTexture("assets\\restartUI.png", Textures::restartUI);
    CreateTexture("assets\\restartUI_2.png", Textures::restartUI_2);
    CreateTexture("assets\\image0.png", Textures::linePuzzle);
    CreateTexture("assets\\image1.png", Textures::blackPuzzle);
    CreateTexture("assets\\image2.png", Textures::curvePuzzle);
    CreateTexture("assets\\imageStart.png", Textures::imageStart);//curve start
    CreateTexture("assets\\imageEnd.png", Textures::imageEnd); //curve end
    CreateTexture("assets\\image0-1.png", Textures::image01); //rotation Line
    CreateTexture("assets\\image2-1.png", Textures::curve2Puzzle); //rotation Curve
    CreateTexture("assets\\levelButton.png", Textures::levelButton);
    CreateTexture("assets\\levelButton_2.png", Textures::levelButton_2);
    CreateTexture("assets\\character.png", Textures::character);
    CreateTexture("assets\\clear.png", Textures::clear);
    CreateTexture("assets\\level.png", Textures::level);
    CreateTexture("assets\\failScreen.png", Textures::failScreen);
    CreateTexture("assets\\next.png", Textures::next);
    CreateTexture("assets\\yellow.png", Textures::yellow);
    CreateTexture("assets\\background2.png", Textures::background2);
    CreateTexture("assets\\mini.png", Textures::mini);
    CreateTexture("assets\\image3.png", Textures::threePuzzle);
    CreateTexture("assets\\image4.png", Textures::vPuzzle);
    CreateTexture("assets\\image5.png", Textures::movePuzzle);
  
}
void Texture::Load3()
{
    CreateTexture("assets\\00.png", Textures::num0);
    CreateTexture("assets\\01.png", Textures::num1);
    CreateTexture("assets\\02.png", Textures::num2);
    CreateTexture("assets\\03.png", Textures::num3);
    CreateTexture("assets\\04.png", Textures::num4);
    CreateTexture("assets\\05.png", Textures::num5);
    CreateTexture("assets\\06.png", Textures::num6);
    CreateTexture("assets\\07.png", Textures::num7);
    CreateTexture("assets\\8.png", Textures::num8);
    CreateTexture("assets\\9.png", Textures::num9);
    CreateTexture("assets\\image4_11.png", Textures::VPuzzle2); //rotation V
    CreateTexture("assets\\left_turn.png", Textures::leftTurn);
    CreateTexture("assets\\imageEnd2.png", Textures::lineEnd);
    CreateTexture("assets\\imageStart2.png", Textures::lineStart);
    CreateTexture("assets\\image_auto3.png", Textures::autoLine);
    CreateTexture("assets\\image_auto2.png", Textures::autoV);
    CreateTexture("assets\\image_auto1.png", Textures::autoCurve);
    CreateTexture("assets\\imageEndAuto1.png", Textures::qutoEnd);
    CreateTexture("assets\\55.png", Textures::yellowPuzzle);
    CreateTexture("assets\\click_left.png", Textures::clickLeft);
    CreateTexture("assets\\click_right.png", Textures::clickRight);
    CreateTexture("assets\\finish_solving.png", Textures::clickPlayButton);
    CreateTexture("assets\\then_click.png", Textures::clickPlayButton2);
    CreateTexture("assets\\levelButton1.png", Textures::level1);
    CreateTexture("assets\\levelButton1_2.png", Textures::leve1p);
    CreateTexture("assets\\levelButton2.png", Textures::level2);
    CreateTexture("assets\\levelButton2_2.png", Textures::level2p);
    CreateTexture("assets\\levelButton3.png", Textures::level3);
    CreateTexture("assets\\levelButton3_2.png", Textures::level3p);
    CreateTexture("assets\\levelButton4.png", Textures::level4);
    CreateTexture("assets\\levelButton4_2.png", Textures::level4p);
    CreateTexture("assets\\levelButton5.png", Textures::level5);
    CreateTexture("assets\\levelButton5_2.png", Textures::level5p);
    CreateTexture("assets\\levelButton6.png", Textures::level6);
    CreateTexture("assets\\levelButton6_2.png", Textures::level6p);
    CreateTexture("assets\\levelButton7.png", Textures::level7);
    CreateTexture("assets\\levelButton7_2.png", Textures::level7p);
   
}
void Texture::Load4()
{
    CreateTexture("assets\\levelButton8.png", Textures::level8);
    CreateTexture("assets\\levelButton8_2.png", Textures::level8p);
    CreateTexture("assets\\levelButton9.png", Textures::level9);
    CreateTexture("assets\\levelButton9_2.png", Textures::level9p);
    CreateTexture("assets\\levelButton10.png", Textures::level10);
    CreateTexture("assets\\levelButton10_2.png", Textures::level10p);
    CreateTexture("assets\\levelButton11.png", Textures::level11);
    CreateTexture("assets\\levelButton11_2.png", Textures::level11p);
    CreateTexture("assets\\locked.png", Textures::levelLock);
    CreateTexture("assets\\checkX.png", Textures::fullCheck);
    CreateTexture("assets\\checkO.png", Textures::fullCheck2);
    CreateTexture("assets\\arrow_left.png", Textures::volumeL);
    CreateTexture("assets\\arrow_right.png", Textures::volumeR);
    CreateTexture("assets\\quit.png", Textures::quitL);
    CreateTexture("assets\\quit2.png", Textures::quitLp);
    CreateTexture("assets\\option.png", Textures::optionL);
    CreateTexture("assets\\music.png", Textures::musicL);
    CreateTexture("assets\\bar0.png", Textures::bar0);
    CreateTexture("assets\\fullscreen.png", Textures::fullScrenL);
    CreateTexture("assets\\resume.png", Textures::resume);
    CreateTexture("assets\\resume2.png", Textures::resume2);
    CreateTexture("assets\\backtomain.png", Textures::backtomain);
    CreateTexture("assets\\backtomain2.png", Textures::backtomain2);
    CreateTexture("assets\\background3.png", Textures::background3);
    CreateTexture("assets\\credits.png", Textures::credit);
    CreateTexture("assets\\credits2.png", Textures::creatP);
    CreateTexture("assets\\option2.png", Textures::optionLP);
    CreateTexture("assets\\start.png", Textures::start);
    CreateTexture("assets\\start2.png", Textures::startP);
    CreateTexture("assets\\tutorial.png", Textures::tutorial);
    CreateTexture("assets\\tutorial2.png", Textures::tutorialP);
    CreateTexture("assets\\title.png", Textures::title);
	CreateTexture("assets\\gameControls.png", Textures::controls);
	CreateTexture("assets\\credits1.png", Textures::credit1);
	CreateTexture("assets\\credits3.png", Textures::credit2);
	CreateTexture("assets\\credits4.png", Textures::credit3);
	CreateTexture("assets\\controls.png", Textures::controlButton);
	CreateTexture("assets\\controls2.png", Textures::controlButtonP);
    CreateTexture("assets\\back.png", Textures::back);
    CreateTexture("assets\\ending1.png", Textures::ending1);
    CreateTexture("assets\\ending2.png", Textures::ending2);
}
void Texture::DeleteTexture() noexcept
{
    glCheck(glDeleteTextures(1, &textureHandle));
}



Texture::~Texture() noexcept
{
    DeleteTexture();

}

Texture& Texture::operator=(Texture&& other) noexcept
{
    if (this == &other)
        return *this;
    DeleteTexture();
    textureHandle = other.textureHandle;
    width = other.width;
    height = other.height;
    other.textureHandle = 0;
    other.width = 0;
    other.height = 0;
    return *this;
}

