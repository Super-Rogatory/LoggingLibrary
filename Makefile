.PHONY: clean All

All:
	@echo "----------Building project:[ LoggingLibrary - Debug ]----------"
	@cd "LoggingLibrary" && "$(MAKE)" -f  "LoggingLibrary.mk"
clean:
	@echo "----------Cleaning project:[ LoggingLibrary - Debug ]----------"
	@cd "LoggingLibrary" && "$(MAKE)" -f  "LoggingLibrary.mk" clean
