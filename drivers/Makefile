all: acpi serial keyboard ide

.PHONY: acpi serial ide keyboard clean

acpi:
	@$(MAKE) -sC acpi

serial:
	@$(MAKE) -sC serial

ide:
	@$(MAKE) -sC ide

keyboard:
	@$(MAKE) -sC keyboard

clean:
	$(MAKE) -sC acpi clean
	$(MAKE) -sC serial clean
	$(MAKE) -sC ide clean
	$(MAKE) -sC keyboard clean
