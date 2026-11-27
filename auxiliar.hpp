#ifndef AUXILIAR_HPP
#define AUXILIAR_HPP

#include <string>

#define ALERT_TEXT "\033[1;31m [ALERT: FILE INTEGRITY COMPROMISED] \033[0m"
#define OK_TEXT "\033[1;32m [FILES ARE SAFE] \033[0m"
#define ATTENTION_TEXT "\033[1;33m [FILE REQUIRES ATTENTION] \033[0m"

void alert(std::string filename);

void no_alert();

void attention(std::string filename);

#endif 