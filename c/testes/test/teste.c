#include "unity/unity.h"
#include "../funcoes.h"

void setUp(){ //função do unity executada antes de todos os testes

}

void tearDown(){ //função executada depois de todos os testes

}

void test_soma(){
    TEST_ASSERT_EQUAL(10,  soma(5,5)); //equals só funcionam para inteiros, não funcionam para float por causa da precisão
}

void test_float(){
    TEST_ASSERT_FLOAT_WITHIN(0.0001,2.0,2.0);
}

void test_ignore(){
    TEST_IGNORE(); //ignora os testes desta função
    TEST_ASSERT_FALSE(1==2); //deve passar pq testa a desigualdade
    TEST_ASSERT(1==1); //testa igualdade
    //neste caso o frame considera os dois testes desta função como um teste único
}

void test_string(){
    TEST_ASSERT_EQUAL_STRING("HELLO", "HELLO");
}

void test_string_falha(){
    char resultado[] = "OLA";
    TEST_ASSERT_EQUAL_STRING("HELLO", resultado);
}

void test_message(){
    TEST_ASSERT_MESSAGE(1==2, "O teste com mensagem falhou!");
}

int main(void){
    UNITY_BEGIN(); //macro que inicializa o unity

    RUN_TEST(test_soma); //roda os testes
    RUN_TEST(test_float); 
    RUN_TEST(test_ignore); 
    RUN_TEST(test_string); 
    RUN_TEST(test_message); 
    RUN_TEST(test_string_falha); 

    return UNITY_END(); //encerra o unity
}