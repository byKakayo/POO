#pragma once
#include <bits/stdc++.h>

//Criação da classe do contador
class Limited_Counter {
    int val_min; //Valor mínimo do contador
    int val_max; //Valor máximo do contador
    int val;     //Valor atual do contador
  public:
    //Inicializar o contador com valor mínimo e máximo
    Limited_Counter(int min, int max): val_min(min), val_max(max), val(min) {}
    //Inicializar o contador apenas com valor máximo
    Limited_Counter(int max): val_min(0), val_max(max), val(0) {}
    //Incrementa o valor atual do contador se possível
    Limited_Counter &Limited_Counter :: operador++(){
      if(val < val_max){
        val = val+1;
      }
      return *this;
    };
    Limited_Counter Limited_Counter :: operador++(int){
      if(val < val_max){
        Limited_Counter tmp{*this};
        ++(*this);
        return tmp;
      }
    };
    //Decrementa o valor atual do contador se possível
    Limited_Counter &Limited_Counter :: operador--(){
      if(val < val_max){
        val = val-1;
      }
      return *this;
    };
    Limited_Counter Limited_Counter :: operador--(int){
      if(val < val_max){
        Limited_Counter tmp{*this};
        --(*this);
        return tmp;
      }
    };
    //Incrementa um valor ao valor atual
    Limited_Counter &Limited_Counter :: operator+=(int x){

    };
    void up_by(int x){
      //Se o valor for negativo: decrementa
      if(x < 0){
        down_by(abs(-x));
      //Se for possível incrementar o valor
      }else if(val+x < val_max){
        val = val+x;
      //Se não for possível incrementar o valor
      }else{
        val = val_max;
      }
      return;
    };
    //Decrementa um valor ao valor atual
    void down_by(int x){
      //Se o valor for negativo: incrementa
      if(x < 0){
        up_by(abs(-x));
      //Se for possível decrementar o valor
      }else if(val-x > val_min){
        val = val-x;
      //Se não for possível decrementar o valor
      }else{
        val = val_min;
      }
      return;
    };
    //Retorna o valor atual do contador
    int value() const { return val; }
};
