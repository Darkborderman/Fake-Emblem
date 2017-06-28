#include "audio.h"

audio::audio()
{
    player = new QMediaPlayer;
    sf=new QMediaPlayer;
    srand(time(NULL));
    int x=rand()%5;
    if(x==0) player->setMedia(QUrl::fromLocalFile("/home/divik/Desktop/2017-pd2-project-3-fire-emblem/res/audio/track_9.wav"));
    if(x==1) player->setMedia(QUrl::fromLocalFile("/home/divik/Desktop/2017-pd2-project-3-fire-emblem/res/audio/track_10.wav"));
    if(x==2) player->setMedia(QUrl::fromLocalFile("/home/divik/Desktop/2017-pd2-project-3-fire-emblem/res/audio/track_12.wav"));
    if(x==3) player->setMedia(QUrl::fromLocalFile("/home/divik/Desktop/2017-pd2-project-3-fire-emblem/res/audio/track_13.wav"));
    if(x==4) player->setMedia(QUrl::fromLocalFile("/home/divik/Desktop/2017-pd2-project-3-fire-emblem/res/audio/track_17.wav"));
    player->setVolume(100);
    player->play();
}
void audio::move()
{
    sf->setMedia(QUrl::fromLocalFile("/home/divik/Desktop/2017-pd2-project-3-fire-emblem/res/audio/walksound.wav"));
    sf->setVolume(100);
    sf->play();
}

void audio::select()
{
    sf->setMedia(QUrl::fromLocalFile("/home/divik/Desktop/2017-pd2-project-3-fire-emblem/res/audio/cursor-select1.wav"));
    sf->setVolume(50);
    sf->play();
}

void audio::panel()
{
    sf->setMedia(QUrl::fromLocalFile("/home/divik/Desktop/2017-pd2-project-3-fire-emblem/res/audio/cursor-select2.wav"));
    sf->setVolume(50);
    sf->play();
}
