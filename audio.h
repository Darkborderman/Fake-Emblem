#ifndef AUDIO_H
#define AUDIO_H

#include<QtMultimedia/QMediaPlayer>

class audio
{
public:
    audio();
    QMediaPlayer *player,*sf;
    void move();
    void select();
    void panel();
};

#endif // AUDIO_H
