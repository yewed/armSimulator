/*
  Armator - simulateur de jeu d'instruction ARMv5T � but p�dagogique
  Copyright (C) 2011 Guillaume Huard
  Ce programme est libre, vous pouvez le redistribuer et/ou le modifier selon les
  termes de la Licence Publique G�n�rale GNU publi�e par la Free Software
  Foundation (version 2 ou bien toute autre version ult�rieure choisie par vous).

  Ce programme est distribu� car potentiellement utile, mais SANS AUCUNE
  GARANTIE, ni explicite ni implicite, y compris les garanties de
  commercialisation ou d'adaptation dans un but sp�cifique. Reportez-vous � la
  Licence Publique G�n�rale GNU pour plus de d�tails.

  Vous devez avoir re�u une copie de la Licence Publique G�n�rale GNU en m�me
  temps que ce programme ; si ce n'est pas le cas, �crivez � la Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307,
  �tats-Unis.

  Contact: Guillaume.Huard@imag.fr
  ENSIMAG - Laboratoire LIG
  51 avenue Jean Kuntzmann
  38330 Montbonnot Saint-Martin
*/
#include "arm_branch_other.h"
#include "arm_constants.h"
#include "util.h"
#include <debug.h>
#include <stdlib.h>


int arm_branch(arm_core p, uint32_t ins) {
    uint32_t value;
    int immed;
    immed = get_bits(ins,23,0);
    if (get_bit(ins,24))
	arm_write_register(p,14,arm_read_register(p,15)-4); // R14 = adresse de retour

    immed = immed | (get_bit(ins,23) ? 0x3F000000 : 0);
    immed <<=2;

    value = arm_read_register(p,15) + immed; //le ternaire met a 1 ou a 0 tous les bits de 26 a 32 si on a une valeur negative ou non 
    arm_write_register(p,15,value);
    return 0;
}

int arm_coprocessor_others_swi(arm_core p, uint32_t ins) {
    if (get_bit(ins, 24)) {
        /* Here we implement the end of the simulation as swi 0x123456 */
        if ((ins & 0xFFFFFF) == 0x123456)
            exit(0);
        return SOFTWARE_INTERRUPT;
    } 
    return UNDEFINED_INSTRUCTION;
}

int arm_miscellaneous(arm_core p, uint32_t ins) {
    return UNDEFINED_INSTRUCTION;
}
