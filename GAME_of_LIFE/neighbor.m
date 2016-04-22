function flag = neighbor(r, c,M)%arguments row column
     flag = 0;%number of alive cells 
     GAME_MAP = M;
    for i = r-1:r+1
        for j = c-1:c+1
            if GAME_MAP(i,j) == 1
                flag = flag+1;
            end
        end
    end
    
    if GAME_MAP(r,c) == 1
        flag = flag-1;
    end
    

end
