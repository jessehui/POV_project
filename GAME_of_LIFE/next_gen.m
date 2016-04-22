function con = next_gen(r,c,M)
    flag = neighbor(r,c,M);
    GAME_MAP = M;
    switch flag
        case 0
            GAME_MAP(r,c) = 0;
        case 1
            GAME_MAP(r,c) = 0;
        case 4
            GAME_MAP(r,c) = 0;
        case 5
            GAME_MAP(r,c) = 0;
        case 6
            GAME_MAP(r,c) = 0;
        case 7
            GAME_MAP(r,c) = 0;
        case 8
            GAME_MAP(r,c) = 0;
        
        case 2
            GAME_MAP(r,c) = GAME_MAP(r,c);
        case 3
            GAME_MAP(r,c) = 1; 
         
    end
   con = GAME_MAP(r,c);
end

