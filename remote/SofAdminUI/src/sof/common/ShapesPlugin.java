package sof.common;

import org.eclipse.ui.plugin.AbstractUIPlugin;

/**
 * The plugin class (singleton).
 * <p>
 * This instance can be shared between all extensions in the plugin. Information
 * shared between extensions can be persisted by using the PreferenceStore.
 * </p>
 * 
 * @author magr74
 */
public class ShapesPlugin extends AbstractUIPlugin {

/** 
 * Single plugin instance. 
 */
private static ShapesPlugin singleton;

/**
 * Returns the shared plugin instance.
 */
public static ShapesPlugin getDefault() {
	return singleton;
}

/** 
 * The constructor. 
 */
public ShapesPlugin() {
	if (singleton == null) {
		singleton = this;
	}
}


}