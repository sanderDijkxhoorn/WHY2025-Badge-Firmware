import pytest
from pytest_embedded import Dut


@pytest.mark.esp32s3
def test_esp32_spi_load_ram_example(dut: Dut) -> None:
    # Check initial connection
    dut.expect("Connected to target")

    # Check RAM loading process
    dut.expect("Loading app to RAM")
    dut.expect("Start loading")
    dut.expect("Downloading")  # This may appear multiple times with different addresses
    dut.expect("Finished loading")

    # Check target output
    dut.expect("Hello world!")
