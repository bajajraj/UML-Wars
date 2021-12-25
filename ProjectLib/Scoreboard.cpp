/**
 * @file Scoreboard.cpp
 * @author Team Grady Win (Ian Hay)
 */

#include "pch.h"

#include "Scoreboard.h"

/// Font size of the words
const int FontSizeWords = 30;

/// Font size of the numbers
const int FontSizeNumbers = 60;

/// How much green is needed to get the correct scoreboard color
const int GreenSaturation = 128;

/// How far the numbers are from the top in pixels
const int DistanceNumbersTop = 25;

/// How far the words are from the top in pixels
const int DistanceWordsTop = 100;

/// The offset left or right of the words if they are not the center word
const int OffCenterXValue = 400;

/**
 * Consturctor for scoreboard
 * @param game the game the scoreboard is for
 */
Scoreboard::Scoreboard(Game *game) : Item(game)
{

}


void Scoreboard::PlaceTextCentered(wxGraphicsContext *graphics, std::string word, double x, double y)
{
    wxFont font(wxSize(0, FontSizeWords),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_BOLD);
    graphics->SetFont(font, wxColour(0, GreenSaturation, 0));
    double wid, hit, wid2, hit2;
    wxGraphicsBrush brush;

    //This obtains the correct value to put over the given word
    int numberToUse;
    if (word == "Correct") { numberToUse = mCorrect; }
    if (word == "Unfair") { numberToUse = mUnfair; }
    if (word == "Missed") { numberToUse = mMissed; }

    //gets the center value of the word
    graphics->GetTextExtent(word, &wid, &hit);
    graphics->DrawText(word, x - (wid / 2), y, brush);

    //Sets the number on the scoreboard in the center of word right above it
    font.SetPointSize(FontSizeNumbers);
    graphics->SetFont(font, wxColour(0, GreenSaturation, 0));
    graphics->GetTextExtent(std::to_string(numberToUse), &wid2, &hit2);
    graphics->DrawText(std::to_string(numberToUse), x  - (wid2 / 2), DistanceNumbersTop, brush);


}


void Scoreboard::Draw(wxGraphicsContext *graphics)
{
    PlaceTextCentered(graphics, "Correct", -OffCenterXValue, DistanceWordsTop);
    PlaceTextCentered(graphics, "Missed", 0, DistanceWordsTop);
    PlaceTextCentered(graphics, "Unfair", OffCenterXValue, DistanceWordsTop);
}

void Scoreboard::Reset()
{
    mMissed = 0;
    mCorrect = 0;
    mUnfair = 0;
}