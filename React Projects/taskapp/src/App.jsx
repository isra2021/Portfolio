import { useState } from "react";
import TaskRow from "./components/TaskRow";
import TaskBanner from "./components/TaskBanner";
import TaskCreator from "./components/TaskCreator";
import VisibilityControl from "./components/VisibilityControl";

function App() {

  const [userName, setUserName] = useState('isra')

  const [taskItem, setTaskItem] = useState([
    { name: 'Task One', done: false },
    { name: 'Task Two', done: false },
    { name: 'Task Tree', done: true },
    { name: 'Task Four', done: false },
  ])

  const [showCompleted, setShowCompleted] = useState(true)


  const createNewTask = (taskName) => {
    if (!taskItem.find(t => t.name === taskName)) {
      setTaskItem([...taskItem, { name: taskName, done: false }]);
    }
  };

  const toggleTask = (task) =>
    setTaskItem(
      taskItem.map(t => (t.name === task.name ? { ...t, done: !t.done } : t))
    );

  const taskTableRows = (doneValue) =>
    taskItem
      .filter(task => task.done === doneValue)
      .map(task => (
        <TaskRow key={task.name} task={task} toggleTask={toggleTask} />
      )); 

  return (
    <div>
      <TaskBanner userName={userName} taskItems={taskItem} />
      <div className="container-fluid">
        <TaskCreator callback={createNewTask} />
        <table className="table table-striped table-bordered">
          <thead>
            <tr>
              <th>Description</th>
              <th>Done</th>
            </tr>
          </thead>
          <tbody>{taskTableRows(false)}</tbody>
        </table>
        <div className="bg-secondary text-white text-center p-2">
          <VisibilityControl
            description="Completed Tasks"
            isChecked={showCompleted}
            callback={checked => setShowCompleted(checked)}
          />
        </div>
        {showCompleted && (
          <table className="table table-striped table-bordered">
            <thead>
              <tr>
                <th>Description</th>
                <th>Done</th>
              </tr>
            </thead>
            <tbody>{taskTableRows(true)}</tbody>
          </table>
        )}
      </div>
    </div>
  );
}

export default App;