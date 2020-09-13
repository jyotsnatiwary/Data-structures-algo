clc
clear all
a=zeros(1080,1920);
b=uint8(a);
c=b;
 
for i=10:210
	for j=360:380
		b(j,i)=255;
	end
end
 
for i=10:210
	for j=720:740
		b(j,i)=255;
	end
end
 
for i=100:120
	for j=380:720
		b(j,i)=255;
	end
end
 
for i=1890:1910
	for j=360:740
		b(j,i)=255;
	end
end
 
for i=1690:1710
	for j=360:740
		b(j,i)=255;
	end
end
 
for i=1710:1890
	for j=720:740
		b(j,i)=255;
	end
end
 
for i=370:390
	for j=360:740
		b(j,i)=255;
	end
end
 
for i=390:590
	for j=720:740
		b(j,i)=255;
	end
end
 
for i=620:640
	for j=360:740
		b(j,i)=255;
	end
end
 
for i=640:840
	for j=360:380
		b(j,i)=255;
	end
end
 
for i=640:840
	for j=720:740
		b(j,i)=255;
	end
end
 
for i=840:860
	for j=360:740
		b(j,i)=255;
	end
end
 
k=890; l=360;
 
for m=1:191
	for i=k:k+20
		for j=l:l+1
			b(j,i)=255;
		end
	end
 
	if(j==740)
	break;
	end
	k=k+1; l=l+2;
end
 
k=1080; l=740;
for m=1:191
	for i=k:k+20
		for j=l-1:l
			b(j,i)=255;
		end
	end
	if(j==360)
	break;
	end
	k=k+1; l=l-2;
end
 
for i=1320:1340
	for j=360:740
		b(j,i)=255;
	end
end
 
for i=1340:1540
	for j=360:380
		b(j,i)=255;
	end
end
 
for i=1340:1540
	for j=720:740
		b(j,i)=255;
	end
end
 
for i=1340:1440
	for j=540:560
		b(j,i)=255;
	end
end
 
e(:,:,1)=b;
e(:,:,2)=c;
e(:,:,3)=c;
imshow(e);