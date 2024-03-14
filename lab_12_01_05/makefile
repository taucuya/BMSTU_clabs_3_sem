CC := gcc
CFLAGS := -std=c99 -Wall -Werror
SRC := src
SRC_DINAMIC := src_dinamic
OUT := out
OUT_DINAMIC := out_dinamic
EXE_DIR := exe
UNIT_DIR := unit_tests

UFLAGS := -lcheck -lpthread -lrt -lsubunit -lm

SOURCE_FILES := $(wildcard $(SRC)/*.c)
SRC_OBJECTS := $(SOURCE_FILES:$(SRC)/%.c=$(OUT)/%.o)
SRC_OBJECTS := $(filter-out $(OUT)/main.o, $(SRC_OBJECTS))

SOURCE_FILES_D := $(wildcard $(SRC_DINAMIC)/*.c)
SRC_OBJECTS_D := $(SOURCE_FILES:$(SRC_DINAMIC)/%.c=$(OUT_DINAMIC)/%.o)
SRC_OBJECTS_D := $(filter-out $(OUT_DINAMIC)/main.o, $(SRC_OBJECTS_D))

UNIT_FILES := $(wildcard $(UNIT_DIR)/*.c)
UNIT_OBJECTS := $(UNIT_FILES:$(UNIT_DIR)/%.c=$(OUT)/%.o)
UNIT_OBJECTS := $(filter-out $(OUT)/check_main.o, $(UNIT_OBJECTS))

STATIC_LIB_DIR := libraries/stat_lib
STATIC_LIB_NAME := stat_lib.a
STATIC_EXE_NAME := $(EXE_DIR)/stat_app.exe

DYNAMIC_LIB_1_DIR := libraries/dyn_lib_1
DYNAMIC_LIB_1_NAME := dyn_lib_1.so
DYNAMIC_EXE_1_NAME := $(EXE_DIR)/dynamic_app_1.exe

DYNAMIC_LIB_2_DIR := libraries/dyn_lib_2
DYNAMIC_LIB_2_NAME := dyn_lib_2.so
DYNAMIC_EXE_2_NAME := $(EXE_DIR)/dynamic_app_2.exe

.PHONY: all unit clean

all: static dynamic1 dynamic2 unit

static: $(STATIC_LIB_DIR)/$(STATIC_LIB_NAME) $(STATIC_EXE_NAME)

dynamic1 dynamic2: CFLAGS += -fPIC
dynamic1 dynamic2: LDFLAGS += -shared

dynamic1: $(DYNAMIC_LIB_1_DIR)/$(DYNAMIC_LIB_1_NAME) $(DYNAMIC_EXE_1_NAME)
dynamic2: $(DYNAMIC_LIB_2_DIR)/$(DYNAMIC_LIB_2_NAME) $(DYNAMIC_EXE_2_NAME)

unit: $(EXE_DIR)/unit_tests.exe $(OUT)/check_main.o $(STATIC_LIB_DIR)/$(STATIC_LIB_NAME)

$(STATIC_EXE_NAME): $(SRC)/main.c $(STATIC_LIB_DIR)/$(STATIC_LIB_NAME)
	$(CC) $(CFLAGS) $^ -o $@

$(DYNAMIC_EXE_1_NAME): $(SRC)/main.c $(SRC_OBJECTS)
	$(CC) $(CFLAGS) -L. -Wl,-rpath=$(DYNAMIC_LIB_1_DIR) $^ -o $@

$(DYNAMIC_EXE_2_NAME): $(SRC_DINAMIC)/main.c $(SRC_OBJECTS_D)
	$(CC) $(CFLAGS) -ldl $^ -o $@

$(EXE_DIR)/unit_tests.exe: $(OUT)/check_main.o $(STATIC_LIB_DIR)/$(STATIC_LIB_NAME)
	$(CC) $^ -o $@ $(UFLAGS)

$(STATIC_LIB_DIR)/$(STATIC_LIB_NAME): $(UNIT_OBJECTS) $(SRC_OBJECTS)
	ar cr $@ $^

$(DYNAMIC_LIB_1_DIR)/$(DYNAMIC_LIB_1_NAME): $(SRC_OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(DYNAMIC_LIB_2_DIR)/$(DYNAMIC_LIB_2_NAME): $(SRC_OBJECTS_D)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(OUT)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(OUT_DINAMIC)/%.o: $(SRC_DINAMIC)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(OUT)/%.o: $(UNIT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXE_DIR)/*.exe $(OUT)/*.o $(STATIC_LIB_DIR)/$(STATIC_LIB_NAME) $(DYNAMIC_LIB_1_DIR)/$(DYNAMIC_LIB_1_NAME) \
		$(DYNAMIC_LIB_2_DIR)/$(DYNAMIC_LIB_2_NAME)