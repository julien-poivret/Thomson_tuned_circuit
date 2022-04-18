#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct{
	long double L;
	long double C;
	long double Fc;
        int init;
}resonant_data;

/* 
     Thomson resonant frequency v2
     two values must be provided at minimum,
     the third must be initialized with a zero...
     the data base memory is then writed with the correct  matching values.
*/
int tuned_circuit(long double L, long double C, long double Fc,resonant_data* data){
	if(L==0.0 && C && Fc){
		data->L = ((1/Fc)/2)*((1/Fc)/2)/C;
                data->C=C;
                data->Fc=Fc;
                return 1;
	}
	if(C==0.0 && L && Fc){
		data->C = (((1/Fc)/2)*((1/Fc)/2))/L;
                data->L = L;
                data->Fc = Fc;
                return 1;
	}
	if(Fc==0.0 && C && L){
		data->Fc = 1/(2*M_PI*sqrt(L*C));
                data->L = L;
                data->C = C;
                return 1;
	}
		fprintf(stderr,"\33[1;1H\33[2J\33[31mError, at least 2 non null values  must be provided at minimum !\33[0m\n");
		exit(3);
	return 0;

};
	
// Data preprocessing for arguments handling.
void format_argv(char* argv[],resonant_data* data){
	data->L = atof(argv[1]);
	data->C = atof(argv[2]);
	data->Fc = atof(argv[3]);
	data->init = 1;
}

int main(int argc,char* argv[]){
	// Arguments handling condition.
	char help[70]="(3 cli arguments):  1 inductance, 2 capacitance, 3 Resonant Frequency"; 
	if(argc==1){
		printf("%s\n",help);
		return EXIT_SUCCESS;
	}else if(argc!=4){
		printf("3 arguments must be provided.\n");				
		return EXIT_FAILURE;
	}
        resonant_data Thomson= {.init=1};
        format_argv(argv,&Thomson);
	tuned_circuit(Thomson.L,Thomson.C,Thomson.Fc,&Thomson);
	printf("\33[1;1H\33[2J\33[34mTuned resonant circuit:\33[0m\33[3;1HResonant with L:\33[33m%6.3Le \33[0mC:\33[33m%6.3Le \33[0mFc:\33[33m%6.3LeHz\33[0m\n",Thomson.L,Thomson.C,Thomson.Fc); 
return EXIT_SUCCESS;
}
