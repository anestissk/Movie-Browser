#pragma once
#include <string>
#include <iostream>

class Movie {

    float m_pos[2]; // array for the coordinates of each movie
    bool m_highlighted = false; 
    bool m_active = false;
public:

    void draw();
    void update();

    //Constructor
    Movie(std::string title, int year, std::string director,
        std::string mainActor1, std::string mainActor2,
        std::string genre1, std::string genre2, std::string summary, std::string imagepath,std::string imagepath2)
        : title_(title), year_(year), director_(director),
        mainActor1_(mainActor1), mainActor2_(mainActor2),
        genre1_(genre1), genre2_(genre2), summary_(summary), imagepath_(imagepath), imagepath2_(imagepath2) {
    }
    //setters
    void setTitle(std::string title) {
        title_ = title;
    }
    void setYear(int year) {
        year_ = year;
    }
    void setDirector(std::string director) {
        director_ = director;
    }
    void setMainActor1(std::string mainActor1) {
        mainActor1_ = mainActor1;
    }
    void setMainActor2(std::string mainActor2) {
        mainActor2_ = mainActor2;
    }
    void setGenre1(std::string genre1) {
        genre1_ = genre1;
    }
    void setGenre2(std::string genre2) {
        genre2_ = genre2;
    }
    void setSummary(std::string summary) {
        summary_ = summary ;
    }
    void setImagepath(std::string imagepath) {
        imagepath_ = imagepath;
    }
   void setImagepath2(std::string imagepath2) {
        imagepath2_ = imagepath2;
    }
    void setPosX(float x) { m_pos[0] = x; }
    void setPosY(float y) { m_pos[1] = y; }


    //getters
    std::string getTitle() const {
        return title_;
    }
    int getYear() const {
        return year_;
    }
    std::string getDirector() const {
        return director_;
    }
    std::string getMainActor1() const {
        return mainActor1_;
    }
    std::string getMainActor2() const {
        return mainActor2_;
    }
    std::string getGenre1() const {
        return genre1_;
    }
    std::string getGenre2() const {
        return genre2_;
    }
    std::string getSummary() const {
        return summary_;
    }
    std::string getImagepath() const {
        return imagepath_;
    }
    std::string getImagepath2() const {
        return imagepath2_;
    }

    float getPosX() { return m_pos[0]; }
    float getPosY() { return m_pos[1]; }

    std::string title_;
    int year_;
    std::string director_;
    std::string mainActor1_;
    std::string mainActor2_;
    std::string genre1_;
    std::string genre2_;
    std::string summary_;
    std::string imagepath_;
    std::string imagepath2_;



    void setHighlight(bool h) {

        m_highlighted = h;
    }

    bool contains(float x, float y);
    void setActive(bool a) {m_active=a;}


};