document.getElementById("dataForm").addEventListener("submit", function(event) {
    event.preventDefault();
  
    const value1 = document.getElementById("value1").value;
    const value2 = document.getElementById("value2").value;
  
    addDataToTable(value1, value2);
    clearForm();
  });
  
  function addDataToTable(value1, value2) {
    const table = document.getElementById("dataTable");
    const newRow = table.insertRow(table.rows.length);
  
    const cell1 = newRow.insertCell(0);
    const cell2 = newRow.insertCell(1);
  
    cell1.innerHTML = value1;
    cell2.innerHTML = value2;
  }
  
  function clearForm() {
    document.getElementById("value1").value = "";
    document.getElementById("value2").value = "";
  }
  