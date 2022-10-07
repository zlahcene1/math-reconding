#include "ground.hpp"

/* ------------------- ARGUMENT CHECKER -------------------------*/

void helper()
{
    std::cout << "SYNOPSIS\n\t./groundhog period\n\nDESCRIPTION"
            << "\n\tperiod\t\tthe number of days defining a period"<< std::endl;
}
void is_a_great_arg(char const *arg)
{
    if (!arg)
        exit(FAILURE);
    for (int i = 0; arg[i] && arg[i] != '\0'; i++)
        if (arg[i] < '0' || arg[i] > '9')
            exit(FAILURE);
}

std::size_t CHECKer(const std::string& str)
{
    const char *strr = str.c_str();

    if (str.compare("STOP") == 0) return STOP;
    for (int i = 0; strr[i] != '\0'; i++) {
        if (strr[i] == '-' && i == 0) return EXIT;
        if (strr[i] == '.' && i > 0 && str[i + 1]) i++;
        if (strr[i] >'9' || strr[i] < '0') return EXIT;
    }
    return std::atof(str.c_str()) != 0 ? CONTINUE : EXIT;
}

/* -------------------- DISPLAYER ----------------------------*/

void displays(int i, int nb, Ground * cl)
{
    if (i < nb)
        printf("g=nan\t\tr=nan%%\t\ts=nan\n");
    else if (i == nb)
        printf("g=nan\t\tr=nan%%\t\ts=%.2f\n", cl->S);
    else
        printf("g=%.2f\t\tr=%.0f%%\t\ts=%.2f\n", cl->G, cl->R, cl->S);
}


void display_stop(void)
{
    std::cout << "Global tendency switched ";
    std::cout << "n" << " times" << std::endl;
    exit(SUCCESS);
}

/* ----------------------- CALCULATORS -----------------------------------*/

void eR(Ground cl)
{

    float tmp = std::atof(cl._input[cl._input.size() - cl._argument - 1].c_str());
    cl.R = round((std::atof(cl._input.back().c_str()) - tmp) / tmp * 100);    
}

void eS(Ground cl, int idx)
{
     int N, i;
     float Ai, S1, S2, M;
     float V, Ec;

    printf("GRound:%f %d", cl.S, idx);
     printf ("Bienvenue dans mon programme de calcul de la moyenne, variance et\necart type a partir d'une serie de valeurs.\n");
     printf ("\nEntrez le nombre de valeurs N de votre serie : ");
     scanf ("%d", &N);

     S1 = 0;
     S2 = 0;

     for (i=1;i<=N;i++)
     {
         printf ("\nEntrez vos valeurs : ");
         scanf ("%f", &Ai);
         S1 = S1+Ai;
         S2 = S2+Ai*Ai;
     }

     M = S1/N;
     V = S2/N-M*M;
     Ec = sqrt (V);

     printf ("\nLa moyenne de la serie vaut : %f\n", M);
     printf ("\nLa variance de la serie vaut : %f\n", V);
     printf ("\nL'ecart type de la serie vaut : %2lf\n", roundf(Ec));

     printf ("\nRMadmann Prod©\n");

    // float tmp, result;

    // for (int i = idx - cl._argument; i < idx;i++)
    //     tmp = tmp + std::atof(cl._input[i].c_str());
    // tmp /= cl._argument;
    // for (int i = idx - cl._argument; cl._argument < i; i++)
    //     result += pow(std::atof(cl._input[i].c_str()) - tmp, 2);
    // cl.S = sqrt(result / cl._argument);
}

void eG(Ground cl)
{
    printf("%2.f ", cl.R);
    exit(SUCCESS);
}

/* ---------------------- PROGRAM ------------------- */

void Ground::meteo(int nb, Ground cl)
{
    std::size_t st; 
    cl._argument = nb;

    for(int i = 0; true; i++) 
    {   
        getline(std::cin, _cmd);
        cl._input.push_back(_cmd);
    

        if ((st = CHECKer(_cmd)) == STOP)
            display_stop();
        else if (st == EXIT)
            exit(FAILURE);
        else if (st == CONTINUE) {
           if (i >= cl._argument)
                eS(cl, i);
           displays(i++, nb, &cl);

        } else
            i *= 1;
    }

}

int main(int ac, char **av)
{
    std::string arg_catch;
    Ground ground; 

    if (ac == 2)
        arg_catch.assign(av[1]);
    else return 84;

    is_a_great_arg(arg_catch.c_str());
    arg_catch.compare("-h") == 0 ? helper() : ground.meteo(atoi(av[1]), ground);
    return 0;
}