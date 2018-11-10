/*
  #Título: Não Durma no Trânsito
  
  #Autores:  
    Gabriel Almeida Fontes - 32471@aluno.diocesanocaruaru.g12.br
    Lucas Emanuel Camilo Bezerra - 2015270@aluno.diocesanocaruaru.g12.br
    Luiz Henrique Fonseca Braga de Vasconcelos - 2015234@aluno.diocesanocaruaru.g12.br
    Maria Eduarda Bezerra Feliciano - 2015258@aluno.diocesanocaruaru.g12.br
    Maria Victória Correia da Silva - 2015240@aluno.diocesanocaruaru.g12.br
     
  #Orientador: Prof. Diógenes Souza - diogenessouza@diocesanocaruaru.g12.br
  
  #Repositório do projeto no GitHub: https://github.com/Diocesano/nao_durma
  
  #Descrição:
  -> O nosso projeto tem o objetivo de diminuir o número de acidentes no trânsito causados
    por sonolência. O intúito do giroscópio é para assim que o indivíduo abaixe a cabeça no cochilo,
    um sinal ser enviado ao buzzer e assim ele apitará acordando o condutor.
 
  #Componentes:
    ->1 placa baseada no Arduino Uno R3, utilizando o
      microcontrolador Atmel Atmega328p
    ->1 Módulo Acelerômetro e Giroscópio MPU-6050
    ->1 Buzzer ativo 5v

  
  #Conexões:

                                      +-----+
         +----[PWR]-------------------| USB |--+
         |                            +-----+  |
         |         GND/RST2  [ ][ ]            |
         |       MOSI2/SCK2  [ ][ ]  A5/SCL[ ] |    
         |          5V/MISO2 [ ][ ]  A4/SDA[ ] |    
         |                             AREF[ ] |
         |                              GND[ ] |
         | [ ]N/C                    SCK/13[ ] |   
         | [ ]IOREF                 MISO/12[ ] |   
         | [ ]RST                   MOSI/11[ ]~|   
         | [ ]3V3    +---+               10[ ]~|   
         | [ ]5v    -| A |-               9[ ]~|   
         | [ ]GND   -| R |-               8[ ] |   
         | [ ]GND   -| D |-                    |
         | [ ]Vin   -| U |-               7[ ] |   
         |          -| I |-               6[ ]~|   
         | [ ]A0    -| N |-               5[ ]~|   
         | [ ]A1    -| O |-               4[ ] |   
         | [ ]A2     +---+           INT1/3[ ]~|   
         | [ ]A3                     INT0/2[ ] |   
         | [ ]A4/SDA  RST SCK MISO     TX>1[ ] |   
         | [ ]A5/SCL  [ ] [ ] [ ]      RX<0[ ] |   
         |            [ ] [ ] [ ]              |
         |  UNO_R3    GND MOSI 5V  ____________/
          \_______________________/

~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ 
LICENÇA - Copyright 2018 Gabriel, Lucas, Luiz, Maria Eduarda, Maria Victória e Diógenes
~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   
    Este programa é um software livre; você pode redistribuí-lo e/ou 
    modificá-lo dentro dos termos da Licença Pública Geral GNU como 
    publicada pela Fundação do Software Livre (FSF); na versão 3 da 
    Licença, ou (na sua opinião) qualquer versão.
    Este programa é distribuído na esperança de que possa ser útil, 
    mas SEM NENHUMA GARANTIA; sem uma garantia implícita de ADEQUAÇÃO
    a qualquer MERCADO ou APLICAÇÃO EM PARTICULAR. Veja a
    Licença Pública Geral GNU para maiores detalhes.
    Você deve ter recebido uma cópia da Licença Pública Geral GNU junto
    com este programa. Se não, veja <http://www.gnu.org/licenses/>.
  
  ------------------------------------------------------------------------------------      

 */
 
#include <AcceleroMMA7361.h>
 
AcceleroMMA7361 giroscopio;

int x;
int y;
int z;
int buzzer = 9;
 
void setup()
{
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  giroscopio.begin(13, 12, 11, 10, A0, A1, A2);
  giroscopio.setARefVoltage(3.3);  //sets the AREF voltage to 3.3V
  giroscopio.setSensitivity(LOW);  //sets the sensitivity to +/-6G
  giroscopio.calibrate();

}
 
void loop()
{
  x = giroscopio.getXRaw();
  y = giroscopio.getYRaw();
  z = giroscopio.getZRaw();
  Serial.print("x: ");
  Serial.println(x);
  Serial.print("Y: ");
  Serial.println(y);
  Serial.print("Z: ");
  Serial.println(z);
  Serial.println();
  
  if(y>700){
     digitalWrite(buzzer,HIGH);                                  
  }
  else{
    digitalWrite(buzzer,LOW);
  }
}
