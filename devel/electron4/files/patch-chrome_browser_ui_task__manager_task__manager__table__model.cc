--- chrome/browser/ui/task_manager/task_manager_table_model.cc.orig	2019-03-15 06:37:06 UTC
+++ chrome/browser/ui/task_manager/task_manager_table_model.cc
@@ -457,13 +457,13 @@ base::string16 TaskManagerTableModel::GetText(int row,
           ? stringifier_->backgrounded_string()
           : stringifier_->foregrounded_string();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN: {
       const int fd_count = observed_task_manager()->GetOpenFdCount(tasks_[row]);
       return fd_count >= 0 ? base::FormatNumber(fd_count)
                            : stringifier_->n_a_string();
     }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
     case IDS_TASK_MANAGER_MEMORY_STATE_COLUMN: {
       return stringifier_->GetMemoryStateText(
@@ -623,7 +623,7 @@ int TaskManagerTableModel::CompareValues(int row1,
       return BooleanCompare(is_proc1_bg, is_proc2_bg);
     }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN: {
       const int proc1_fd_count =
           observed_task_manager()->GetOpenFdCount(tasks_[row1]);
@@ -631,7 +631,7 @@ int TaskManagerTableModel::CompareValues(int row1,
           observed_task_manager()->GetOpenFdCount(tasks_[row2]);
       return ValueCompare(proc1_fd_count, proc2_fd_count);
     }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
     default:
       NOTREACHED();
@@ -797,11 +797,11 @@ void TaskManagerTableModel::UpdateRefreshTypes(int col
       type = REFRESH_TYPE_KEEPALIVE_COUNT;
       break;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     case IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN:
       type = REFRESH_TYPE_FD_COUNT;
       break;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
     default:
       NOTREACHED();
