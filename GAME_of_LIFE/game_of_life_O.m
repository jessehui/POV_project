clear all;
clc

%define
DEAD = 0;
ALIVE = 1;
MAX_COL = 20;%matrix column number
MAX_ROW = 32;
GAME_MAP = zeros(MAX_ROW,MAX_COL);
GEN = 20;%generation

%initiative pattern
NEW_MAP = zeros(MAX_ROW,MAX_COL,GEN);
GAME_MAP(4:8,8) = ALIVE;
GAME_MAP(4:8,12) = ALIVE;
GAME_MAP(4,10) = ALIVE;
%GAME_MAP(15,15) = ALIVE;
GAME_MAP(8,10) = ALIVE;

GAME_MAP(14:18,8) = ALIVE;
GAME_MAP(14:18,12) = ALIVE;
GAME_MAP(14,10) = ALIVE;
%GAME_MAP(15,15) = ALIVE;
GAME_MAP(18,10) = ALIVE;

GAME_MAP(24:28,8) = ALIVE;
GAME_MAP(24:28,12) = ALIVE;
GAME_MAP(24,10) = ALIVE;
%GAME_MAP(15,15) = ALIVE;
GAME_MAP(28,10) = ALIVE;

figure
imagesc(GAME_MAP);
title( sprintf('Generation 1') );

NEW_MAP(:,:,1) = GAME_MAP;
 
%display
g = 2;
while g <= GEN
    for i = 2:MAX_ROW-1
        for j = 2:MAX_COL-1
            NEW_MAP(i,j,g) = next_gen(i,j,NEW_MAP(:,:,g-1));
        end
    end
    figure
    imagesc(NEW_MAP(:,:,g));
    title( sprintf('Generation %d',g) );
    g = g+1;
end

%s = LED_dis(1,NEW_MAP);
%dec = LED_dis_v2(1,NEW_MAP);
%s = LED_dis(2,NEW_MAP)

%get decimal value for each 74hc595
%function LED_DEC = LED_dis_v2(Gen_Num, Mat)
dec_pic2 = LED_dis_v2(2,NEW_MAP)
dec_pic = LED_dis_v2(GEN,NEW_MAP)










