COMPILER = g++
CFLAGS = -Wall -std=c++17

SRC = main.cpp src/Client/Client.cpp src/Account/Account.cpp src/Bank/Bank.cpp src/Account/PartnerAccount/PartnerAccount.cpp

main: $(SRC)
	$(COMPILER) $(CFLAGS) $(SRC) -o main