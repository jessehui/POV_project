% obtain decimal value of each number which 
% can be directely put into 74hc595 function

function LED_DEC = LED_dis_v2(Gen_Num, Mat) 
     img = Mat(:,:,Gen_Num);
     chip = zeros(20,4);
     for i = 1:20
        col(:,i) = img(:,i);
        for j = 1:32
            col(j,i) = num2str(col(j,i));%number --> string every element
        end
            
        for j = 1:4 %32 LEDs,  4 chips of 595 (8 each)
            
                s = strcat(col(1+(j-1)*8,i),col(2+(j-1)*8,i));
                for k = 3:8
                    s = strcat(s, col(k+(j-1)*8,i));
                end    
                
                s = bin2dec(s);
                chip(i,j) = s;
        end
     end
     
     LED_DEC = chip;

end

