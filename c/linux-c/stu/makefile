objects = main.o GetTotalScore.o GetAverScore.o
main:$(objects)
main.o:main.c	GetTotalScore.h	GetAverScore.h
GetTotalScore.o:GetTotalScore.c GetTotalScore.h	
GetAverScore.o:GetAverScore.c GetAverScore.h
clean:
	rm	*.o
	rm	main