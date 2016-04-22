function LED_HEX = LED_dis(Gen_Num, Mat) %obtain HEX number of LED bar which makes it easy to check
    img = Mat(:,:,Gen_Num); %get the image of specified generation
    %col = zeros(20,1);
    str=cell(1) ;
    for i = 1:20
        col(:,i) = img(:,i); %get columns of the image
        for j = 1:32
        col(j,i) = num2str(col(j,i));%number --> string every element
        end
        
        s = strcat(col(1,i),col(2,i)); %first string link
        for k = 3:32
            s = strcat(s, col(k,i)); %put all string together
        end
        
        s
        s = bin2dec(s);
        s = dec2hex(s);
        t = sprintf(s);
        
        str{i} = t;
    end

    LED_HEX = str;
end
