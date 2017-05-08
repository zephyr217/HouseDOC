/*package layout;

import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import com.heartware.heartware.R;

public class SubPage2 extends Fragment {

    public SubPage2() {}

    // TODO: Rename and change types and number of parameters
    public static SubPage2 newInstance() {
        SubPage2 fragment = new SubPage2();
        Bundle args = new Bundle();
        fragment.setArguments(args);
        return fragment;
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_sub_page2, container, false);
        
        String[] recomandari = new String[]{"Recomandarea 1: qweqeqweq","Recomandarea 2: qweqweqw", "Recomandarea 3: qeqweqw","Recomandarea 4: qweqeqwe","Recomandarea 5: qweqweqwew", "Recomandarea 6: qweqwewq"};

        ListView recListView=(ListView)view.findViewById(R.id.recomandariListView);
        ArrayAdapter<String> recListAdapter = new ArrayAdapter<String>(getActivity(),android.R.layout.simple_list_item_1,android.R.id.text1,recomandari);
        recListView.setAdapter(recListAdapter);
        return view;
    }
}
*/