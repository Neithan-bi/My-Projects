function deleteItem(id) {
 fetch(`/items/${id}`, {
 method: 'DELETE'
 }).then(response => response.text())
 .then(data => {
 console.log(data);
 location.reload();
 });
}
function editItem(id, name, description) {
 const newName = prompt('Enter new name:', name);
 const newDescription = prompt('Enter new description:', description);
 if (newName && newDescription) {
 fetch(`/items/${id}`, {
 method: 'PUT',
 headers: {
 'Content-Type': 'application/json'
 },
 body: JSON.stringify({ name: newName, description: newDescription })
 }).then(response => response.text())
 .then(data => {
 console.log(data);
 location.reload();
 });
 }
}
